#include "pch.h"
#include "GPIOEmulator.h"


void Blink(GPIO&);
void SetLamp(GPIO&);

TEST(GoogleMockDemo, BlinkTest) {
	GPIOEmulator mygpio;
	EXPECT_CALL(mygpio, pinMode(1, 1)).Times(1); /* Once call only*/
	Blink(mygpio);
}



