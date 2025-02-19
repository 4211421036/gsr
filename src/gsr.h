#ifndef GSR_H
#define GSR_H

#include <Arduino.h>

class GSR {
public:
    GSR(int pin, float vcc);
    void begin();
    float readResistance();
    bool isStressDetected();

private:
    int pin;
    float vcc;
    int threshold;
};

#endif
