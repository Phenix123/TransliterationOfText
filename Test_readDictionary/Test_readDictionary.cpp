#include "pch.h"
#include "CppUnitTest.h"
#include "../TransliterationOfText/function.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestreadDictionary
{
	TEST_CLASS(TestreadDictionary)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::vector<string> ErrorList;
			Assert::AreEqual(readDictionary("file", { "dictionary", "is" }, ErrorList), true);
		}
	};
}
