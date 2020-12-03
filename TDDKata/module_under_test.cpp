#include "GPIO.h"


/* Testing function */

void Blink(GPIO &gpio) {
    gpio.pinMode(1, 1);
}


void SetLamp(GPIO& gpio) {
    while(!gpio.digitalRead(3));
    gpio.digitalWrite(10,1);
}