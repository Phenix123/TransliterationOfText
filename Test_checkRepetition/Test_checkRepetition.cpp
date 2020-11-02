#include "pch.h"
#include "CppUnitTest.h"
#include "../TransliterationOfText/function.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestcheckRepetition
{
	TEST_CLASS(TestcheckRepetition)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<string> ErrorList;
			vector<string> dictionary;
			Assert::AreEqual(checkRepetition(dictionary, ErrorList), false);
		}
	};
}
