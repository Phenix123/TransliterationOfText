#include "pch.h"
#include "CppUnitTest.h"
#include "../TransliterationOfText/function.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestcheckDictionary
{
	TEST_CLASS(TestcheckDictionary)
	{
	public:

		TEST_METHOD(NotErrors)
		{
			vector<string> ErrorList;
			vector<string> dictionary{"А A", "Б B", "В V"};
			Assert::AreEqual(checkDictionary(dictionary, ErrorList), false);
		}

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

		TEST_METHOD(MoreOneTranslation)
		{
			vector<string> ErrorList;
			vector<string> dictionary = { "А A", "Б B", "В V", "Г B" };
			Assert::AreEqual(checkDictionary(dictionary, ErrorList), true);
		}

		TEST_METHOD(ThreeWordInStr)
		{
			vector<string> ErrorList;
			vector<string> dictionary = { "А A", "Б B B", "В V"};
			Assert::AreEqual(checkDictionary(dictionary, ErrorList), true);
		}

		TEST_METHOD(OneWordInStr)
		{
			vector<string> ErrorList;
			vector<string> dictionary = { "А A", "Б", "В V" };
			Assert::AreEqual(checkDictionary(dictionary, ErrorList), true);
		}

		TEST_METHOD(ManySymb)
		{
			vector<string> ErrorList;
			vector<string> dictionary = { "А A", "Ш Sh", "В V" };
			Assert::AreEqual(checkDictionary(dictionary, ErrorList), false);
		}
	};
}
