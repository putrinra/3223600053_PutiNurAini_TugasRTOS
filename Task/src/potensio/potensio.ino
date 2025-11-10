#define POT 1  // ADC1_CH0

TaskHandle_t potTask;

void potTaskCode(void *pvParameters) {
  for(;;) {
    int val = analogRead(POT);
    Serial.printf("Potentiometer (GPIO 1): %d\n", val);
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  xTaskCreatePinnedToCore(potTaskCode, "Pot", 2048, NULL, 1, &potTask, 1);
}

void loop() {
  Serial.println("Core 0: Pot on Core 1");
  vTaskDelay(5000 / portTICK_PERIOD_MS);
}