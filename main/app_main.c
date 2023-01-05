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
#include "protocol_examples_common.h"

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
static const char *TAG = "Main_MQTT_EXAMPLE";

EventGroupHandle_t connectivity_event_group;

#define BUF_SIZE 256

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1
#define MQTT_CONNECTED BIT2

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
            // printf("MqttPublishQueue: added message to queue Len : %d Queue Data %s \n", payload.len, payload.message);
        }
        else
        {
            printf("MqttPublishQueue:  failed to add message to queue\n");
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

        memset(payload.message, 0, BUF_SIZE);
        strcpy(payload.message, message);
        strcpy(payload.topic, topic);
        payload.len = strlen(message);

        if (xQueueSend(MqttPublishQueue, &payload, 0))
        {
            ESP_LOGI("MqttPublishQueue", "added message to queue Len : %d Queue Data %s \n", payload.len, payload.message);
            // break;
        }
        else
        {
            ESP_LOGE("MqttPublishQueue", "failed to add message to queue\n");
            // break;
        }

        vTaskDelay(7000 / portTICK_PERIOD_MS);
    }
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

    /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
     * Read "Establishing Wi-Fi or Ethernet Connection" section in
     * examples/protocols/README.md for more information about this function.
     */
    ESP_ERROR_CHECK(example_connect());
    esp_log_set_vprintf(&vprintf_into_spiffs);
    connectivity_event_group = xEventGroupCreate();
    MqttPublishQueue = xQueueCreate(20, sizeof(payload_t));

    xTaskCreate(&MqttPublisherTask, "do something with http", 3048, NULL, 1, NULL);
    xTaskCreate(&task2, "Simulate", 3048, NULL, 1, NULL);

    mqtt_app_start();
}

// int logmsg(char *format, va_list args)
// {
// 	char str[256];
// 	/*Extract the the argument list using VA apis */

// 	// va_start(args, format);
// 	vsprintf(str, format, args);
// 	va_end(args);
// 	//printf("From new log Function log size :  %d \n", strlen(str));
// 	//	printf("%s", str);

// 	//xSemaphoreGive(Log_Semaphore);
// 	int len;
// 	// remove newline
// 	len = strlen(str);
// 	if (str[len - 1] == '\n')
// 		str[len - 1] = 0;
// 	//Write to log queue
// 	log_payload_t payload;

// 	memset(payload.message, 0, 256);
// 	memcpy(payload.message, str, strlen(str));

// 	//if (xQueueSendFromISR(log_queue, &payload, pdFALSE))
// 	if (xQueueSend(log_queue, &payload, 0))
// 	{
// 		//	printf("added message to log queue Len : %d Queue Data %s \n", payload.len, payload.message);
// 		//	printf("added message to log queue  \n");

// 		// break;
// 	}
// 	else
// 	{
// 		//	printf("failed to add message to log queue\n");
// 		// break;
// 	}
// 	return 1;
// }
