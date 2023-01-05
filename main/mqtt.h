#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"


#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

#include "esp_log.h"
#include "mqtt_client.h"
#include "main.h"


#define BROKER_URL "mqtt://test.mosquitto.org"
#define TOPIC_NAME "/5onr"

esp_mqtt_client_handle_t client;
extern xQueueHandle MqttPublishQueue;
extern EventGroupHandle_t connectivity_event_group;

#define BUF_SIZE 256
#define DEVICEID "DZ00889654"

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1
#define MQTT_CONNECTED BIT2

typedef struct payload_t
{
    char message[BUF_SIZE];
    char topic[32];
    int len;
} payload_t;

void mqtt_app_start(void);
void MqttPublisherTask(void *params);