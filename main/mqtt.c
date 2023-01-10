#include "mqtt.h"
static const char *TAG = "MQTT";

static void log_error_if_nonzero(const char *message, int error_code)
{
    if (error_code != 0)
    {
        ESP_LOGE(TAG, "Last error %s: 0x%x", message, error_code);
    }
}

static esp_err_t mqtt_event_handler_cb(esp_mqtt_event_handle_t event)
{
    esp_mqtt_client_handle_t client = event->client;
    int msg_id;
    // your_context_t *context = event->context;
    switch (event->event_id)
    {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
        msg_id = esp_mqtt_client_publish(client, "/5onr", "data_3", 0, 1, 0);
        ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);

        // msg_id = esp_mqtt_client_subscribe(client, "/5onr", 0);
        // ESP_LOGI(TAG, "sent subscribe successful, msg_id=%d", msg_id);

        msg_id = esp_mqtt_client_subscribe(client, DEVICEID "/cmd", 1);
        ESP_LOGI(TAG, "sent subscribe successful, msg_id=%d", msg_id);

        // msg_id = esp_mqtt_client_unsubscribe(client, "/5onr");
        // ESP_LOGI(TAG, "sent unsubscribe successful, msg_id=%d", msg_id);
        xEventGroupSetBits(connectivity_event_group, MQTT_CONNECTED);
        break;
    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
        xEventGroupClearBits(connectivity_event_group, MQTT_CONNECTED);

        break;

    case MQTT_EVENT_SUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
        msg_id = esp_mqtt_client_publish(client, "/topic/qos0", "data", 0, 0, 0);
        ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);
        break;
    case MQTT_EVENT_UNSUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_PUBLISHED:
        // ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_DATA:
        ESP_LOGI(TAG, "MQTT_EVENT_DATA");
        ESP_LOGW(TAG, "TOPIC=%.*s\tDATA=%.*s \r", event->topic_len, event->topic, event->data_len, event->data);
        // ESP_LOGI(TAG, "DATA=%.*s\r", event->data_len, event->data);
        break;
    case MQTT_EVENT_ERROR:
        ESP_LOGI(TAG, "MQTT_EVENT_ERROR");
        if (event->error_handle->error_type == MQTT_ERROR_TYPE_TCP_TRANSPORT)
        {
            log_error_if_nonzero("reported from esp-tls", event->error_handle->esp_tls_last_esp_err);
            log_error_if_nonzero("reported from tls stack", event->error_handle->esp_tls_stack_err);
            log_error_if_nonzero("captured as transport's socket errno", event->error_handle->esp_transport_sock_errno);
            ESP_LOGI(TAG, "Last errno string (%s)", strerror(event->error_handle->esp_transport_sock_errno));
        }
        break;
    default:
        ESP_LOGI(TAG, "Other event id:%d", event->event_id);
        break;
    }
    return ESP_OK;
}

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    ESP_LOGD(TAG, "Event dispatched from event loop base=%s, event_id=%d", base, event_id);
    mqtt_event_handler_cb(event_data);
}

void mqttInit(void)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        .uri = BROKER_URL,
    };

    client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, client);
    // esp_mqtt_client_start(client);
    // mqttStart();
}

void mqttStart(void)
{
    xEventGroupWaitBits(connectivity_event_group, WIFI_CONNECTED_BIT, pdFALSE, pdFALSE, portMAX_DELAY);
    esp_mqtt_client_start(client);
}

void MqttPublisherTask(void *params)
{
    payload_t payload;
    char topic[50];
    char data[384];
    while (true)
    {
        // printf("task to send data to cloud ");
        xEventGroupWaitBits(connectivity_event_group, MQTT_CONNECTED, pdFALSE, pdFALSE, portMAX_DELAY);

        if (xQueueReceive(MqttPublishQueue, &payload, portMAX_DELAY) /*&& socket_index > 0*/)
        {
            sprintf(topic, "YCHF/%s/%s", payload.topic, DEVICEID);
            sprintf(data, "{'topic':'%s' ,'data':'%s' ,'deviceID':'%s'}", payload.topic, payload.message,DEVICEID);
            ESP_LOGI("MqttPublishQueue", "Queue Len : %d Queue Data %s ", payload.len, payload.message);
            int msg_id = esp_mqtt_client_publish(client, topic, data, 0, 0, 0);
            ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);
            // printf(" ppp \t[Writing to SPIFFS] %s", data);
        }
        else
        {
            ESP_LOGE("MqttPublishQueue", "failed to read message to queue");
        }

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
