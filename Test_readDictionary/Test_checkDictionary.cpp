#include "pch.h"
#include "CppUnitTest.h"
#include "../TransliterationOfText/function.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestcheckDictionary
{
	TEST_CLASS(TestcheckDictionary)
	{
	public:
		
		TEST_METHOD(DictionaryIsEmpty)
		{
			vector<string> ErrorList;
			vector<string> dictionary;
			Assert::AreEqual(checkDictionary(dictionary, ErrorList), true);
		}

		TEST_METHOD(UnknowSymbol)
		{
			vector<string> ErrorList;
			vector<string> dictionary = {"А A", "Б 3"};
			Assert::AreEqual(checkDictionary(dictionary, ErrorList), true);
		}

		TEST_METHOD(WrongСolumn)
		{
			vector<string> ErrorList;
			vector<string> dictionary = {"А А", "B Б"};
			Assert::AreEqual(checkDictionary(dictionary, ErrorList), true);
		}
	};
}
