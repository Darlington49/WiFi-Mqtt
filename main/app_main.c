/* MQTT (over TCP) Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"
// #include "protocol_examples_common.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

#include "esp_log.h"
#include "mqtt.h"
#include "main.h"
static const char *TAG = "Main";

EventGroupHandle_t connectivity_event_group;

#define BUF_SIZE 256

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1
#define MQTT_CONNECTED BIT2

#define EXAMPLE_ESP_WIFI_SSID "AndroidAP9CB9"
#define EXAMPLE_ESP_WIFI_PASS "00000000"
#define EXAMPLE_ESP_MAXIMUM_RETRY 5

xQueueHandle MqttPublishQueue;

int vprintf_into_spiffs(const char *szFormat, va_list args)
{
    int ret = 0;
    char log_print_buffer[256];

    // // write evaluated format string into buffer
    ret = vsnprintf(log_print_buffer, sizeof(log_print_buffer), szFormat, args);
    payload_t payload;

    // output is now in buffer. write to file.
    if (ret >= 0)
    {
        // // debug output
        // printf(" ppp \t[Writing to SPIFFS] %.*s", ret, log_print_buffer);
        // int msg_id = esp_mqtt_client_publish(client, "/5onr/log", &log_print_buffer, 0, 1, 0);
        // printf("sent publish successful, msg_id=%d", msg_id);

        memset(payload.message, 0, BUF_SIZE);
        strcpy(payload.message, log_print_buffer);
        strcpy(payload.topic, "log");
        payload.len = strlen(log_print_buffer);

        if (xQueueSend(MqttPublishQueue, &payload, 0))
        {
            // break;
            // printf("MqttPublishQueue: added message to queue Len : %d Queue Data %s ", payload.len, payload.message);
        }
        else
        {
            printf("MqttPublishQueue:  failed to add message to queue");
            // break;
        }
    }
    return ret;
}

void task2(void *params)
{
    payload_t payload;
    char message[] = "hi this is a test";
    char topic[] = "data";
    while (true)
    {
        // ESP_LOGI(TAG, "Queue Task fill ");
        // int random = esp_random();
        memset(payload.message, 0, BUF_SIZE);
        // strcpy(payload.message, message);
        sprintf(payload.message, "this is random test :%d", esp_random());
        strcpy(payload.topic, topic);
        payload.len = strlen(message);

        if (xQueueSend(MqttPublishQueue, &payload, 0))
        {
            ESP_LOGI("MqttPublishQueue", "added message to queue Len : %d Queue Data %s", payload.len, payload.message);
            // break;
        }
        else
        {
            ESP_LOGE("MqttPublishQueue", "failed to add message to queue");
            // break;
        }

        vTaskDelay(7000 / portTICK_PERIOD_MS);
    }
}

static void event_handler(void *arg, esp_event_base_t event_base,
                          int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START)
    {
        esp_wifi_connect();
        ESP_LOGI(TAG, "WIFI_EVENT_STA_START");
    }
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
    {
        xEventGroupClearBits(connectivity_event_group, WIFI_CONNECTED_BIT);
        ESP_LOGI(TAG, "Wi-Fi disconnected, trying to reconnect...");
        esp_wifi_connect();
    }
    else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
        xEventGroupSetBits(connectivity_event_group, WIFI_CONNECTED_BIT);
        mqttStart();
    }
}

void wifi_init_sta(void)
{
    // ESP_ERROR_CHECK(esp_netif_init());

    // ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_t instance_got_ip;
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &event_handler,
                                                        NULL,
                                                        &instance_any_id));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        IP_EVENT_STA_GOT_IP,
                                                        &event_handler,
                                                        NULL,
                                                        &instance_got_ip));

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = EXAMPLE_ESP_WIFI_SSID,
            .password = EXAMPLE_ESP_WIFI_PASS,
            /* Setting a password implies station will connect to all security modes including WEP/WPA.
             * However these modes are deprecated and not advisable to be used. Incase your Access point
             * doesn't support WPA2, these mode can be enabled by commenting below line */
            .threshold.authmode = WIFI_AUTH_WPA2_PSK,

            .pmf_cfg = {
                .capable = true,
                .required = false},
        },
    };
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "wifi_init_sta finished.");
}

void app_main(void)
{
    ESP_LOGI(TAG, "[APP] Startup..");
    ESP_LOGI(TAG, "[APP] Free memory: %d bytes", esp_get_free_heap_size());
    ESP_LOGI(TAG, "[APP] IDF version: %s", esp_get_idf_version());

    esp_log_level_set("*", ESP_LOG_INFO);
    esp_log_level_set("MQTT_CLIENT", ESP_LOG_VERBOSE);
    esp_log_level_set("MQTT_EXAMPLE", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT_TCP", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT_SSL", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT", ESP_LOG_VERBOSE);
    esp_log_level_set("OUTBOX", ESP_LOG_VERBOSE);

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    wifi_init_sta();
    // /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
    //  * Read "Establishing Wi-Fi or Ethernet Connection" section in
    //  * examples/protocols/README.md for more information about this function.
    //  */
    // ESP_ERROR_CHECK(example_connect());
    // esp_log_set_vprintf(&vprintf_into_spiffs);
    connectivity_event_group = xEventGroupCreate();
    MqttPublishQueue = xQueueCreate(20, sizeof(payload_t));

    // xTaskCreate(&MqttPublisherTask, "do something with http", 3048, NULL, 1, NULL);
    // xTaskCreate(&task2, "Simulate", 3048, NULL, 1, NULL);

    mqttInit();
}
