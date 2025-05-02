// ThreadCoach ESP32 Firmware: Flex Sensor + IMU + Vibration Feedback
#include <Wire.h>
#include "MPU6050.h"

#define FLEX1_PIN 36  // Thumb
#define FLEX2_PIN 39  // Index
#define FLEX3_PIN 34  // Middle
#define VIBRATION_PIN 5

#define TCA_ADDRESS 0x70
MPU6050 mpu;

void tcaSelect(uint8_t channel) {
  if (channel > 7) return;
  Wire.beginTransmission(TCA_ADDRESS);
  Wire.write(1 << channel);
  Wire.endTransmission();
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  pinMode(VIBRATION_PIN, OUTPUT);

  for (int ch = 0; ch < 2; ch++) {
    tcaSelect(ch);
    mpu.initialize();
    if (!mpu.testConnection()) {
      Serial.print("IMU not detected on channel "); Serial.println(ch);
    }
  }
}

void loop() {
  int flex1 = analogRead(FLEX1_PIN);
  int flex2 = analogRead(FLEX2_PIN);
  int flex3 = analogRead(FLEX3_PIN);

  Serial.print("Flex1:"); Serial.print(flex1);
  Serial.print(" Flex2:"); Serial.print(flex2);
  Serial.print(" Flex3:"); Serial.print(flex3);

  tcaSelect(0); int16_t ax1, ay1, az1; mpu.getAcceleration(&ax1, &ay1, &az1);
  tcaSelect(1); int16_t ax2, ay2, az2; mpu.getAcceleration(&ax2, &ay2, &az2);

  Serial.print(" | IMU1 ax:"); Serial.print(ax1);
  Serial.print(" IMU2 ax:"); Serial.println(ax2);

  if (flex2 > 3000) {
    digitalWrite(VIBRATION_PIN, HIGH);
    delay(200);
    digitalWrite(VIBRATION_PIN, LOW);
  }

  delay(100);
}
