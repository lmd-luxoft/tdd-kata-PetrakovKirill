#pragma once

class GPIO {
public:
    virtual void digitalWrite(int pin, int value);
    virtual int  digitalRead(int pin);
    virtual int  pinMode(int pin, int mode);
};