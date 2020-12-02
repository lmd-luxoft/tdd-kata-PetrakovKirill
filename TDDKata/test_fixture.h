#pragma once
#include "Calculator.h"
#include "pch.h"


class TestFixture : public ::testing::Test {
protected:
	Calculator* calc;

	void SetUp()	override;
	void TearDown() override;
};

