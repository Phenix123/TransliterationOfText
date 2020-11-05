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
			vector<string> ErrorList;
			string dictionaryPath = "symbols.txt";
			vector<string> dictionary;
			Assert::AreEqual(readDictionary(dictionaryPath, dictionary, ErrorList), true);
		}

		TEST_METHOD(TestMethod2)
		{
			vector<string> ErrorList;
			string dictionaryPath = "symbols.txt";
			vector<string> dictionary;
			Assert::AreEqual(readDictionary(dictionaryPath, dictionary, ErrorList), true);
		}

		TEST_METHOD(TestMethod3)
		{
			vector<string> ErrorList;
			string dictionaryPath = "symbols.txt";
			vector<string> dictionary;
			Assert::AreEqual(readDictionary(dictionaryPath, dictionary, ErrorList), true);
		}
	};
}
