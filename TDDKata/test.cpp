#include "pch.h"
#include "Calculator.h"

/*
1.Create a simple String calculator with a method int Add(string numbers)The method can take 0, 1 or 2 numbers, and will 
  return their sum(for an empty string it will return 0) for example “” or “1” or “1, 2”

	•Start with the simplest test case of an empty stringand move to 1 and 2 numbers
	•Remember to solve things as simply as possible so that you force yourself to write tests you did not think about
	•Remember to refactor  after each passing test
*/

TEST(TDDKata, EmptyString) {
	/* Arrange */
	char*      strInput = "";
	int	       result;
	int	       expect = 0;
	Calculator calc;

	/* Act */
	result = calc.Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}


TEST(TDDKata, SingleNum) {
	/* Arrange */
	char*      strInput = "1";
	int	       result;
	int	       expect = 1;
	Calculator calc;

	/* Act */
	result = calc.Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



TEST(TDDKata, SimpleSum) {
	/* Arrange */
	char*      strInput = "1,2";
	int	       result;
	int	       expect = 3;
	Calculator calc;

	/* Act */
	result = calc.Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}


TEST(TDDKata, Token1NotNumber) {
	/* Arrange */
	char*      strInput = "b,2";
	int	       result;
	int	       expect = -1;
	Calculator calc;

	/* Act */
	result = calc.Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



TEST(TDDKata, Token2NotNumber) {
	/* Arrange */
	char*      strInput = "-1,c";
	int	       result;
	int	       expect = -1;
	Calculator calc;

	/* Act */
	result = calc.Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



TEST(TDDKata, TokensNotNumber) {
	/* Arrange */
	char*      strInput = "q,c";
	int	       result;
	int	       expect = -1;
	Calculator calc;

	/* Act */
	result = calc.Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



TEST(TDDKata, BadSplitChar) {
	/* Arrange */
	char*      strInput = "3 2";
	int	       result;
	int	       expect = -2;
	Calculator calc;

	/* Act */
	result = calc.Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



/* 
	Exercise #2
		Allow the Add method to handle an unknown amount of numbers
*/

TEST(TDDKata, Op3) {
	/* Arrange */
	char*      strInput = "3,2,7";
	int	       result;
	int	       expect = 12;
	Calculator calc;

	/* Act */
	result = calc.Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



TEST(TDDKata, Op6) {
	/* Arrange */
	char*      strInput = "3,2,7,10,3,8";
	int	       result;
	int	       expect = 33;
	Calculator calc;

	/* Act */
	result = calc.Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



TEST(TDDKata, Op6BadSymbol) {
	/* Arrange */
	char*      strInput = "3,2,7,x,3,8";
	int	       result;
	int	       expect = -1;
	Calculator calc;

	/* Act */
	result = calc.Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}




/*
	Exercise #3
		Allow the Add method to handle new lines between numbers (instead of commas)
		• the following input is ok:“1\n2,3”(will equal 6)•the following input is NOTok:“1,\n” 
*/

TEST(TDDKata, NewDelimeter) {
	/* Arrange */
	char*      strInput = "1\n2,3";
	int	       result;
	int	       expect = 5;
	Calculator calc;

	/* Act */
	result = calc.Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}



TEST(TDDKata, OpMiss) {
	/* Arrange */
	char*      strInput = "1,\n";
	int	       result;
	int	       expect = -3;
	Calculator calc;

	/* Act */
	result = calc.Add(strInput);

	/* Assert */
	ASSERT_EQ(expect, result);
}