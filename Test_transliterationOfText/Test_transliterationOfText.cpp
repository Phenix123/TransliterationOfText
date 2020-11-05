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
		//{ "a b v g d yo e zh z i j k l m n o p r s t u f x c ch sh shh ' y '' eh yu ya", "а б в г д е ё ж х и й к л м н о п р с т у ф х ц ч ш щ ъ ы ь э ю я" };
		vector<string> dictionary =
		{ "а a",
			"б b",
			"в v",
			"г g",
			"д d",
			"е e",
			"ё yo",
			"ж zh",
			"з z",
			"и i",
			"й j",
			"к k",
			"л l",
			"м m",
			"н n",
			"о o",
			"п p",
			"р r",
			"с s",
			"т t",
			"у u",
			"ф f",
			"х x",
			"ц c",
			"ч ch",
			"ш sh",
			"щ shh",
			"ъ ''",
			"ы y",
			"ь '",
			"э eh",
			"ю yu",
			"я ya",
		};
		TEST_METHOD(SimpleWord)
		{
			vector<string> text = { "privet" };
			vector<string> exp_string = { "привет" };
			if (transliterationOfText(text, dictionary))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);

			//Assert::AreEqual(transliterationOfText(text, dictionary), true);
		}

		TEST_METHOD(MultipleLines)
		{
			vector<string> text = { "privet", "kak ty" }; 
			vector<string> exp_string = { "привет", "как ты" };
			if (transliterationOfText(text, dictionary))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);
		}

		TEST_METHOD(CapitalLetters)
		{
			vector<string> text = { "Privet", "Kak ty" };
			vector<string> exp_string = { "Привет", "Как ты" };
			if (transliterationOfText(text, dictionary))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);

		}

		TEST_METHOD(PunctuationMarks)
		{
			vector<string> text = { "privet.", "kak ty?" };
			vector<string> exp_string = { "привет.", "как ты?" };
			if (transliterationOfText(text, dictionary))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);
		}

		TEST_METHOD(MultiCharacterTranslation)
		{
			vector<string> text = { "Mama progotovila korzh" };
			vector<string> exp_string = { "Мама приготовила корж" };
			if (transliterationOfText(text, dictionary))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);
		}

		TEST_METHOD(ImpossibleTransliteration)
		{
			vector<string> dict = {"п p", "р r"};
			vector<string> text = { "privet" };
			vector<string> exp_string = { "прivet" };
			if (!transliterationOfText(text, dict))
				Assert::AreEqual(vectorAreEqual(text, exp_string), true);
		}
	};
}
