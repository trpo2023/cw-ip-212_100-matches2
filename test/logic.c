#include "libmatches/logic.h"
#include "ctest.h"
#include "libmatches/menu.h"
CTEST(logic_suite, check_inputNum)
{
 int inputNum = 0;
 check_inputNum(inputNum);
 ASSERT_FALSE(check_inputNum(inputNum));
 inputNum = 11;
 		ASSERT_FALSE(check_inputNum(inputNum));
		inputNum = 7;
		ASSERT_TRUE(check_inputNum(inputNum));
		inputNum = 10;
		ASSERT_TRUE(check_inputNum(inputNum));
	   }
		CTEST(logic_suite, check_inputNum2)
	   {
		int inputNum = 5;
		int count = 4;
	    check_inputNum2(inputNum, &count);
		ASSERT_FALSE(check_inputNum2(inputNum, &count));
		inputNum = 7;
		count = 1;
		check_inputNum2(inputNum, &count);
		ASSERT_FALSE(check_inputNum2(inputNum, &count));
		inputNum = 3;
		count = 6;
		check_inputNum2(inputNum, &count);
		ASSERT_TRUE(check_inputNum2(inputNum, &count));
		inputNum = 9;
		count = 26;
		check_inputNum2(inputNum, &count);
		ASSERT_TRUE(check_inputNum2(inputNum, &count));
	   }
	   CTEST(logic_suite, check_compNum)
	   {
		int compNum = 9;
		int count = 4;
		check_compNum(compNum, &count);
		ASSERT_FALSE(check_compNum(compNum, &count));
		compNum = 7;
		count = 6;
		check_compNum(compNum, &count);
		ASSERT_FALSE(check_compNum(compNum, &count));
		compNum = 3;
		count = 6;
		check_compNum(compNum, &count);
		ASSERT_TRUE(check_compNum(compNum, &count));
		compNum = 7;
		count = 15;
		check_compNum(compNum, &count);
		ASSERT_TRUE(check_compNum(compNum, &count));
		}
