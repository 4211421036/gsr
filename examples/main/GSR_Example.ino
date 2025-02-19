#include "gsr.h"

const int GSR_PIN = 34;
const float VCC = 5.0; // Tegangan supply 5V

GSR gsr(GSR_PIN, VCC);

void setup() {
    Serial.begin(9600);
    gsr.begin();
}

void loop() {
    float resistance = gsr.readResistance();
    Serial.print("Resistance: ");
    Serial.println(resistance);

    if (gsr.isStressDetected()) {
        Serial.println("Stress Detected!");
    } else {
        Serial.println("No Stress Detected.");
    }

    delay(1000);
}
