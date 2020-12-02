#pragma once
#include "test_fixture.h"

struct Param {
    std::string op;
    int expected;

    Param(std::string op, int expected) :op(op), expected(expected) {}
};


class TestFixtureWithParam :
    public TestFixture, public ::testing::WithParamInterface<Param>
{
};

