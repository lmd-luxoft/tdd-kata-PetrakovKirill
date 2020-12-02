#include "pch.h"
#include "test_fixture.h"




void TestFixture::SetUp() {
	calc = new Calculator();
}



void TestFixture::TearDown() {
	delete calc;
}