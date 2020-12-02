#include "pch.h"
#include "Calculator.h"
#include "TestFixtureWithParam.h"

TEST_P(TestFixtureWithParam, Sample) {
	/* Arrange */
    std::string op = GetParam().op;
    int expect     = GetParam().expected;
	int result;

	/* Act */
	result = calc->Add(op);

	/* Assert */
	ASSERT_EQ(expect, result);
}
