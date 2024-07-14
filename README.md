"# QR" 
# QR Code Display on OLED using Arduino

This project demonstrates how to generate and display a QR code on an OLED screen using an Arduino board.

## Requirements

- Arduino board (e.g., Arduino Uno, Nano, etc.)
- OLED display (e.g., SSD1306)
- Connecting wires

## Libraries

Make sure you have the following libraries installed in your Arduino IDE:
- Adafruit SSD1306
- Adafruit GFX
- QR code generation library (`qrcode.h`)

## Installation

1. Connect your OLED display to the Arduino board using the following pin configuration:

| OLED Pin | Arduino Pin |
|----------|-------------|
| VCC      | 5V          |
| GND      | GND         |
| SDA      | A4 (SDA)    |
| SCL      | A5 (SCL)    |

2. Open the Arduino IDE and create a new sketch.

3. Copy and paste the following code into your sketch.

4. Upload the sketch to your Arduino board.

## Usage

After uploading the sketch, the OLED display will show the generated QR code.

## License

This project is licensed under the MIT License.
