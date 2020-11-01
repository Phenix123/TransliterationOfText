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
			Assert::AreEqual(checkRepetition({ "dictionary", "is" }, ErrorList), false);
		}
	};
}
