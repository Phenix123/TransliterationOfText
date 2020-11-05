#include "pch.h"
#include "CppUnitTest.h"
#include "../TransliterationOfText/function.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestcheckTransliteration
{
	TEST_CLASS(TestcheckTransliteration)
	{
	public:
		
		TEST_METHOD(SimpleWord)
		{
			vector<string> ErrorsList;
			vector<string> text = {"привет"};
			Assert::AreEqual(checkTransliteration(text, ErrorsList), true);
		}

		TEST_METHOD(FirstSymbolIsNotRus)
		{
			vector<string> ErrorsList;
			vector<string> text = { "iривет" };
			Assert::AreEqual(checkTransliteration(text, ErrorsList), false);
		}

		TEST_METHOD(MiddleSymbolIsNotRus)
		{
			vector<string> ErrorsList;
			vector<string> text = { "прiвет" };
			Assert::AreEqual(checkTransliteration(text, ErrorsList), false);
		}
		TEST_METHOD(LastSymbolIsNotRus)
		{
			vector<string> ErrorsList;
			vector<string> text = { "привеt" };
			Assert::AreEqual(checkTransliteration(text, ErrorsList), false);
		}
		TEST_METHOD(FirstSymbolIsBigAndNotRus)
		{
			vector<string> ErrorsList;
			vector<string> text = { "Iривет" };
			Assert::AreEqual(checkTransliteration(text, ErrorsList), false);
		}
		TEST_METHOD(WithYo)
		{
			vector<string> ErrorsList;
			vector<string> text = { "ёжик" };
			Assert::AreEqual(checkTransliteration(text, ErrorsList), true);
		}
	};
}
