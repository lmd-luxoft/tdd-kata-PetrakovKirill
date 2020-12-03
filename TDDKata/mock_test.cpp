#include "pch.h"
#include "GPIOEmulator.h"

using ::testing::Return;


/* Hardware emulation */


void Blink(GPIO&);
void SetLamp(GPIO&);

TEST(GoogleMockDemo, BlinkTest) {
	GPIOEmulator mygpio;
	EXPECT_CALL(mygpio, pinMode(1, 1)).Times(1); /* Once call only*/
	Blink(mygpio);
}



TEST(GoogleMockDemo, SetLampTest) {
	GPIOEmulator mygpio;

	EXPECT_CALL(mygpio, digitalRead(3))
		.WillOnce(Return(0))
		.WillOnce(Return(1))
		.WillRepeatedly(Return(0));

	EXPECT_CALL(mygpio, digitalWrite(10,1));

	SetLamp(mygpio);
}


