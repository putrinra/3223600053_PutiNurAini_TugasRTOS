#define BUZZER 12

TaskHandle_t buzzerTask;

void buzzerTaskCode(void *pvParameters) {
  pinMode(BUZZER, OUTPUT);
  int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
  int i = 0;
  for(;;) {
    tone(BUZZER, melody[i], 400);
    vTaskDelay(450 / portTICK_PERIOD_MS);
    noTone(BUZZER);
    i = (i + 1) % 8;
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  xTaskCreatePinnedToCore(buzzerTaskCode, "Buzzer", 2048, NULL, 1, &buzzerTask, 1);
}

void loop() {
  Serial.println("Core 0: Buzzer on Core 1");
  vTaskDelay(3000 / portTICK_PERIOD_MS);
}