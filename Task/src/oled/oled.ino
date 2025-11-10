#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

TaskHandle_t oledTask;

void oledTaskCode(void *pvParameters) {
  // GANTI: Wire.begin(SDA, SCL) → GPIO 8, 9
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed"); for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0); display.println("ESP32-S3 OLED"); display.display();

  int count = 0;
  for(;;) {
    display.clearDisplay();
    display.setCursor(0,0);
    display.printf("Core 1 OLED\nCount: %d\nSDA:8 SCL:9", count++);
    display.display();
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  
  // GANTI: Wire.begin(8, 9)
  Wire.begin(8, 9); // SDA = GPIO 8, SCL = GPIO 9

  xTaskCreatePinnedToCore(oledTaskCode, "OLED", 4096, NULL, 1, &oledTask, 1);
}

void loop() {
  Serial.println("Core 0: OLED on Core 1 (SDA:8, SCL:9)");
  vTaskDelay(2000 / portTICK_PERIOD_MS);
}