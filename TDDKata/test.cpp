#include "pch.h"
#include "Calculator.h"
#include "test_fixture.h"



/*
1.Create a simple String calculator with a method int Add(string numbers)The method can take 0, 1 or 2 numbers, and will 
  return their sum(for an empty string it will return 0) for example “” or “1” or “1, 2”

	•Start with the simplest test case of an empty stringand move to 1 and 2 numbers
	•Remember to solve things as simply as possible so that you force yourself to write tests you did not think about
	•Remember to refactor  after each passing test
*/

TEST_F(TestFixture, EmptyString) {
	/* Arrange */
	char*      strInput = "";
	int	       result;
	int	       expect = 0;

	/* Act */
	result = calc->Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}


TEST_F(TestFixture, SingleNum) {
	/* Arrange */
	char*      strInput = "1";
	int	       result;
	int	       expect = 1;

	/* Act */
	result = calc->Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}


/* 
	TODO: Don't use, new implementation in TestFixtureWithParam.cpp and test_p.cpp 
	This commented code should be deleted.
*/
#if 0
TEST_F(TestFixture, SimpleSum) {
	/* Arrange */
	char*      strInput = "1,2";
	int	       result;
	int	       expect = 3;

	/* Act */
	result = calc->Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}


TEST_F(TestFixture, Token1NotNumber) {
	/* Arrange */
	char*      strInput = "b,2";
	int	       result;
	int	       expect = -1;

	/* Act */
	result = calc->Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



TEST_F(TestFixture, Token2NotNumber) {
	/* Arrange */
	char*      strInput = "1,c";
	int	       result;
	int	       expect = -1;

	/* Act */
	result = calc->Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



TEST_F(TestFixture, TokensNotNumber) {
	/* Arrange */
	char*      strInput = "q,c";
	int	       result;
	int	       expect = -1;

	/* Act */
	result = calc->Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



TEST_F(TestFixture, BadSplitChar) {
	/* Arrange */
	char*      strInput = "3 2";
	int	       result;
	int	       expect = -1;

	/* Act */
	result = calc->Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



/* 
	Exercise #2
		Allow the Add method to handle an unknown amount of numbers
*/

TEST_F(TestFixture, Op3) {
	/* Arrange */
	char*      strInput = "3,2,7";
	int	       result;
	int	       expect = 12;

	/* Act */
	result = calc->Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



TEST_F(TestFixture, Op6) {
	/* Arrange */
	char*      strInput = "3,2,7,10,3,8";
	int	       result;
	int	       expect = 33;

	/* Act */
	result = calc->Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



TEST_F(TestFixture, Op6BadSymbol) {
	/* Arrange */
	char*      strInput = "3,2,7,x,3,8";
	int	       result;
	int	       expect = -1;

	/* Act */
	result = calc->Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}




/*
	Exercise #3
		Allow the Add method to handle new lines between numbers (instead of commas)
		• the following input is ok:“1\n2,3”(will equal 6)
		• the following input is NOTok:“1,\n” 
*/

TEST_F(TestFixture, NewDelimeter) {
	/* Arrange */

	/* Act and Assert */
	ASSERT_EQ(calc->Add("1\n2,3"),   6);
	ASSERT_EQ(calc->Add("11,2\n3"), 16);
}



TEST_F(TestFixture, OpMiss) {
	/* Arrange */

	/* Act and Assert */
	ASSERT_EQ(calc->Add("1,\n"), -3);
	ASSERT_EQ(calc->Add("1\n,"), -3);
}


// Exercise #4
// Support different delimiters
// 	• to change a delimiter, the beginning of the string will contain a separate 
// 	  line that looks like this:“//[delimiter]\n[numbers...]” for example “//;\n1;2” should return three where 
// 	  the default delimiter is ‘;’ 
//	• the first line is optional –all existing scenarios should still be supported


TEST_F(TestFixture, UserDelimCorrect) {
	/* Arrange */

	/* Act and Assert */
	ASSERT_EQ(calc->Add("//;\n1;5;10"),     16);
	ASSERT_EQ(calc->Add("//;,|\n1,5|10;1"), 17);
	ASSERT_EQ(calc->Add("//;\n"), 			0);
}



TEST_F(TestFixture, UserDelimIncorrect) {
	/* Arrange */

	/* Act and Assert */
	ASSERT_EQ(calc->Add("//;\n1;55,10"),    -1);
	ASSERT_EQ(calc->Add("//\n1;55,10"),     -1);
	ASSERT_EQ(calc->Add("//;,.1;55,10.22"), -4);
	ASSERT_EQ(calc->Add("//;,.\n1;55,.22"), -3);
}


/*
	5.Calling Add with a negative number will throw an exception “negatives not allowed” 
	  - and the negative that was passed. If there are multiple negatives, 
	  show all of them in the exception message
*/

TEST_F(TestFixture, NegativeArgs) {
	/* Arrange */

	/* Act and Assert */
	ASSERT_EQ(calc->Add("-1,5"),  -2);
	ASSERT_EQ(calc->Add("1,-5"),  -2);
	ASSERT_EQ(calc->Add("-1,-5"), -2);
}


#endif


