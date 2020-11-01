#include "pch.h"
#include "CppUnitTest.h"
#include "../TransliterationOfText/function.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TesttransliterationOfText
{
	TEST_CLASS(TesttransliterationOfText)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(transliterationOfText({ "text" }, { "dictionary" }), true);
		}
	};
}
