## Proyek ini menunjukkan cara menjalankan banyak tugas secara bersamaan (multitasking) pada ESP32-S3 menggunakan FreeRTOS

## Semua ini dijalankan secara bersamaan (pinned ke core 0 atau core 1) untuk menunjukkan kemampuan multitasking dan penggunaan berbagai periferal ESP32-S3.

## Fitur
- Task LED1, LED2, LED3 – blinking dengan interval berbeda
- Task Button1, Button2 – monitoring tombol, cetak ke Serial saat ditekan
- Task Pot – pembacaan analog potensiometer, cetak ke Serial
- Task Encoder – pembacaan rotary encoder, menghitung perubahan count
- Task Servo – menggerakkan servo melalui angle 0°, 90°, 180°
- Task Stepper – menggerakkan motor stepper maju-mundur dengan kecepatan/acceleration yang ditetapkan
- Task OLED – menampilkan teks statis ke layar OLED
- Task Buzzer – manual PWM untuk buzzer sebagai contoh tugas prioritas lebih tinggi (core 1)

## Langkah langkah 
- Buka proyek menggunakan Wokwi
- Sesuaikan wiring
- Upload program yang sesuai
- Verifikasi dan jalankan simulasi
- Amati hasilnya

## Wiring → https://drive.google.com/file/d/1Ox0HvcFrChwxi1f4uVBFZz0dLLQ3GRt3/view?usp=drive_link

## Video Hasil → https://drive.google.com/file/d/1dVOV_lkla07Zedr2-wxu4pFOa9h64IdS/view?usp=drive_link

## Simulasi → https://wokwi.com/projects/447365394127734785