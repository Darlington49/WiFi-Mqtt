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
