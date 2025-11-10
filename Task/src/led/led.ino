#define LED1 13
#define LED2 14
#define LED3 15

TaskHandle_t ledTask;

void ledTaskCode(void *pvParameters) {
  pinMode(LED1, OUTPUT); pinMode(LED2, OUTPUT); pinMode(LED3, OUTPUT);
  int state = 0;
  for(;;) {
    digitalWrite(LED1, state & 1);
    digitalWrite(LED2, state & 2);
    digitalWrite(LED3, state & 4);
    state = (state + 1) % 8;
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  xTaskCreatePinnedToCore(ledTaskCode, "LED", 2048, NULL, 1, &ledTask, 1);
}

void loop() {
  Serial.println("Core 0: LEDs on Core 1");
  vTaskDelay(1000 / portTICK_PERIOD_MS);
}