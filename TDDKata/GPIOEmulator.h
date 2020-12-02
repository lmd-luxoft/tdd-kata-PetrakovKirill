#pragma once
#include "GPIO.h"
#include "gmock/gmock.h"



class GPIOEmulator : public GPIO {
public:
	MOCK_METHOD(void, digitalWrite, (int pin, int value), (override));
	MOCK_METHOD(int, digitalRead, (int pin), (override));
	MOCK_METHOD(int, pinMode, (int pin, int mode), (override));
};