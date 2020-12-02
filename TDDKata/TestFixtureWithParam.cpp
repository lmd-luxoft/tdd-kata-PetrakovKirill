#include "pch.h"
#include "TestFixtureWithParam.h"

/* 
INSTANCE_TEST_CASE_P(ParamsTest, TestFixtureWithParam, 
    ::testing::Values(Param("2,3", 5, Param("3,3", 6)); 
    */

/* Alternative variant */
#include <vector>

std::vector<Param> CreateParametersSet_Simple() {
    std::vector<Param> p;
    p.push_back(Param("2,3", 5));
    p.push_back(Param("4",   4));

    return (p);
}

INSTANTIATE_TEST_CASE_P( Tests_Simple, TestFixtureWithParam, 
    ::testing::ValuesIn(CreateParametersSet_Simple()) );





std::vector<Param> CreateParametersSet_BadDelimiters() {
    std::vector<Param> p;
    p.push_back(Param("2 3;10", -1));
    p.push_back(Param(";40",    -1));

    return (p);
}

INSTANTIATE_TEST_CASE_P( Tests_BadDelimiters, TestFixtureWithParam, 
    ::testing::ValuesIn(CreateParametersSet_BadDelimiters()) );






std::vector<Param> CreateParametersSet_NegativeOps() {
    std::vector<Param> p;
    p.push_back(Param("-1,5",  -2));
	p.push_back(Param("1,-5",  -2));
	p.push_back(Param("-1,-5", -2));

    return (p);
}

INSTANTIATE_TEST_CASE_P( Tests_NegativeOps, TestFixtureWithParam, 
    ::testing::ValuesIn(CreateParametersSet_NegativeOps()) );





std::vector<Param> CreateParametersSet_UserDelimIncorrect() {
    std::vector<Param> p;
	p.push_back(Param("//;\n1;55,10",    -1));
	p.push_back(Param("//\n1;55,10",     -1));
	p.push_back(Param("//;,.1;55,10.22", -4));
	p.push_back(Param("//;,.\n1;55,.22", -3));

    return (p);
}

INSTANTIATE_TEST_CASE_P( Tests_UserDelimIncorrect, TestFixtureWithParam, 
    ::testing::ValuesIn(CreateParametersSet_UserDelimIncorrect()) );





std::vector<Param> CreateParametersSet_UserDelimCorrect() {
    std::vector<Param> p;
    p.push_back(Param("//;\n1;5;10",     16));
	p.push_back(Param("//;,|\n1,5|10;1", 17));
	p.push_back(Param("//;\n", 		   0));

    return (p);
}

INSTANTIATE_TEST_CASE_P( Tests_UserDelimCorrect, TestFixtureWithParam, 
    ::testing::ValuesIn(CreateParametersSet_UserDelimCorrect()) );




std::vector<Param> CreateParametersSet_OpMiss() {
    std::vector<Param> p;

    p.push_back(Param("1,\n", -3));
	p.push_back(Param("1\n,", -3));

    return (p);
}

INSTANTIATE_TEST_CASE_P( Tests_OpMiss, TestFixtureWithParam, 
    ::testing::ValuesIn(CreateParametersSet_OpMiss()) );






std::vector<Param> CreateParametersSet_NewDelimiter() {
    std::vector<Param> p;
    
    p.push_back(Param("1\n2,3",   6));
	p.push_back(Param("11,2\n3", 16));

    return (p);
}

INSTANTIATE_TEST_CASE_P( Tests_NewDelimiter, TestFixtureWithParam, 
    ::testing::ValuesIn(CreateParametersSet_NewDelimiter()) );




std::vector<Param> CreateParametersSet_BadSymbols() {
    std::vector<Param> p;
    
    p.push_back(Param("3,2,7,x,3,8", -1));
	p.push_back(Param("as,1,34,x",   -1));

    return (p);
}

INSTANTIATE_TEST_CASE_P( Tests_BadSymbols, TestFixtureWithParam, 
    ::testing::ValuesIn(CreateParametersSet_BadSymbols()) );





std::vector<Param> CreateParametersSet_ManyOps() {
    std::vector<Param> p;
    
    p.push_back(Param("3,2,7,10,3,8", 33));
	p.push_back(Param("1,2,34,9",     46));
	p.push_back(Param("3,2,7",        12));

    return (p);
}

INSTANTIATE_TEST_CASE_P( Tests_ManyOps, TestFixtureWithParam, 
    ::testing::ValuesIn(CreateParametersSet_ManyOps()) );