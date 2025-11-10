#define CLK 10   // Tetap
#define DT  11   // Tetap
#define SW  7    // GANTI DARI 12 → 7

TaskHandle_t encTask;
volatile int counter = 0;
int lastCLK = HIGH;

void IRAM_ATTR isr() {
  int curr = digitalRead(CLK);
  if (curr != lastCLK && curr == LOW) {
    counter += (digitalRead(DT) == LOW) ? 1 : -1;
  }
  lastCLK = curr;
}

void encTaskCode(void *pvParameters) {
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(CLK), isr, CHANGE);

  int lastCount = 0;
  for(;;) {
    if (counter != lastCount) {
      Serial.printf("Encoder: %d\n", counter);
      lastCount = counter;
    }
    if (digitalRead(SW) == LOW) {
      Serial.println("Encoder Button (GPIO 7) Pressed!");
      counter = 0;
      vTaskDelay(300 / portTICK_PERIOD_MS);
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  xTaskCreatePinnedToCore(encTaskCode, "Encoder", 4096, NULL, 1, &encTask, 1);
}

void loop() {
  Serial.println("Core 0: Encoder on Core 1 (CLK:10, DT:11, SW:7)");
  vTaskDelay(1000 / portTICK_PERIOD_MS);
}