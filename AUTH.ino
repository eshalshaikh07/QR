#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <qrcode.h>

// Define OLED display parameters
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // Reset pin # (or -1 if sharing Arduino reset pin)

// Create an OLED display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// QR code object
QRCode qrcode;

// Function to draw the QR code on the OLED display
void drawQRCode(QRCode *qrcode) {
  display.clearDisplay();
  int scale = 2;  // Scale factor for QR code (increased for better visibility)

  for (uint8_t y = 0; y < qrcode->size; y++) {
    for (uint8_t x = 0; x < qrcode->size; x++) {
      if (qrcode_getModule(qrcode, x, y)) {
        display.fillRect(x * scale, y * scale, scale, scale, SSD1306_WHITE);
      }
    }
  }

  display.display();
}

void setup() {
  // Initialize the Serial Monitor for debugging
  Serial.begin(115200);

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.display();
  delay(2000); // Pause for 2 seconds
  display.clearDisplay();
}

void loop() {
  if (Serial.available() > 0) {
    // Read the number from Serial Monitor
    String input = Serial.readString();
    input.trim(); // Remove any leading/trailing whitespace

    // Check if input is a valid number
    if (input.length() > 0 && input.toInt() != 0) {
      // Print input number to Serial Monitor
      Serial.print("Received number: ");
      Serial.println(input);

      // Generate QR code with the input number
      uint8_t qrcodeData[qrcode_getBufferSize(3)];
      qrcode_initText(&qrcode, qrcodeData, 3, ECC_LOW, input.c_str());

      // Draw the QR code on the OLED display
      drawQRCode(&qrcode);
    } else {
      Serial.println("Invalid input. Please enter a valid number.");
    }
  }
}
