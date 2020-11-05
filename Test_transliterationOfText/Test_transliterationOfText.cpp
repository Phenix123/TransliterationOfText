#include "pch.h"
#include "CppUnitTest.h"
#include "../TransliterationOfText/function.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TesttransliterationOfText
{
	TEST_CLASS(TesttransliterationOfText)
	{
	private:
		bool vectorAreEqual(vector<string>& left, vector<string>& right)
		{
			if (left.size() != right.size())
				return false;

			for (int i = 0; i < left.size(); i++)
			{
				if (left.at(i).size() != right.at(i).size())
					return false;

				for (int j = 0; j < left.at(i).size(); j++)
				{
					if (left.at(i).at(j) != right.at(i).at(j))
						return false;
				}
			}
			return true;
		}
	public:
		vector<string> ErrorsList;//{ "a b v g d yo e zh z i j k l m n o p r s t u f x c ch sh shh ' y '' eh yu ya", "а б в г д е ё ж х и й к л м н о п р с т у ф х ц ч ш щ ъ ы ь э ю я" };
		vector<string> dictionary =
		{   "А A",
			"Б B",
			"В V",
			"Г G",
			"Д D",
			"Е E",
			"Ё Yo",
			"Ж Zh",
			"З Z",
			"И I",
			"Й J",
			"К K",
			"Л L",
			"М M",
			"Н N",
			"О O",
			"П P",
			"Р R",
			"С S",
			"Т T",
			"У U",
			"Ф F",
			"Х H",
			"Ц C",
			"Ч Ch",
			"Ш Sh",
			"Щ Shh",
			"Ъ Bb",
			"Ы Y",
			"Ь Dd",
			"Э Eh",
			"Ю Yu",
			"Я Ya",
		};
		TEST_METHOD(SimpleWord)
		{
			vector<string> text = { "privet" };
			vector<string> exp_string = { "привет" };
			if (transliterationOfText(text, dictionary, ErrorsList))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);
			else
				Assert::Fail;

			//Assert::AreEqual(transliterationOfText(text, dictionary), true);
		}

		TEST_METHOD(MultipleLines)
		{
			vector<string> text = { "privet", "kak ty" }; 
			vector<string> exp_string = { "привет", "как ты" };
			if (transliterationOfText(text, dictionary, ErrorsList))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);
			else
				Assert::Fail;
		}

		TEST_METHOD(CapitalLetters)
		{
			vector<string> text = { "Privet", "Kak ty" };
			vector<string> exp_string = { "Привет", "Как ты" };
			if (transliterationOfText(text, dictionary, ErrorsList))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);
			else
				Assert::Fail;

		}

		TEST_METHOD(PunctuationMarks)
		{
			vector<string> text = { "privet.", "kak ty?" };
			vector<string> exp_string = { "привет.", "как ты?" };
			if (transliterationOfText(text, dictionary, ErrorsList))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);
			else
				Assert::Fail;
		}

		TEST_METHOD(MultiCharacterTranslation)
		{
			vector<string> text = { "Mama prigotovila korzh" };
			vector<string> exp_string = { "Мама приготовила корж" };
			if (transliterationOfText(text, dictionary, ErrorsList))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);
			else
				Assert::Fail;
		}

		TEST_METHOD(ImpossibleTransliteration)
		{
			vector<string> dict = {"П P", "Р R"};
			vector<string> text = { "privet" };
			vector<string> exp_string = { "прivet" };
			if (!transliterationOfText(text, dict, ErrorsList))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);
			else
				Assert::Fail;
		}

		TEST_METHOD(WithYoSymbol)
		{
			vector<string> text = { "Yozhik" };
			vector<string> exp_string = { "Ёжик" };
			if (!transliterationOfText(text, dictionary, ErrorsList))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);
			else
				Assert::Fail;
		}

		TEST_METHOD(WithChSymbol)
		{
			vector<string> text = { "Chto" };
			vector<string> exp_string = { "Цхто" };
			if (!transliterationOfText(text, dictionary, ErrorsList))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);
			else
				Assert::Fail;
		}
	};
}
