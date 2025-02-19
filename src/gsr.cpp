#include "gsr.h"

GSR::GSR(int pin, float vcc) {
    this->pin = pin;
    this->vcc = vcc;
    this->threshold = 0;
}

void GSR::begin() {
    long sum = 0;
    for (int i = 0; i < 500; i++) {
        int sensorValue = analogRead(this->pin);
        sum += sensorValue;
        delay(5);
    }
    this->threshold = sum / 500;
    Serial.print("Threshold = ");
    Serial.println(this->threshold);
}

float GSR::readResistance() {
    int sensorValue = analogRead(this->pin);
    float vout = (sensorValue / 1023.0) * this->vcc;
    float rSkin = (this->vcc - vout) / (vout / 100000); // Assuming a 100kOhm resistor in series
    return rSkin;
}

bool GSR::isStressDetected() {
    int sensorValue = analogRead(this->pin);
    int temp = this->threshold - sensorValue;
    if (abs(temp) > 50) {
        sensorValue = analogRead(this->pin);
        temp = this->threshold - sensorValue;
        if (abs(temp) > 50) {
            return true;
        }
    }
    return false;
}
