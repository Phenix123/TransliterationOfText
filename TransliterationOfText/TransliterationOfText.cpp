#include <iostream>
#include "function.h"
#pragma warning(disable:4018)

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	string dictionaryPath; // Путь к словарю
	string textPath; // Путь к исходному тексту

	if (argc > 1)
	{
		textPath = argv[1];
		dictionaryPath = argv[2];
	}
	else
	{
		cout << "Input text path" << endl;
		cin >> textPath;
		cout << "Input dictionary path" << endl;
		cin >> dictionaryPath;
		/*textPath = "1.text.txt";
		dictionaryPath = "symbols.txt";*/
	}

	transliteration(textPath, dictionaryPath);

	return 0;
}

void transliteration(string& textPath, string& dictionaryPath)
{
	vector<string> text; // Исходный текст для транслитерации
	vector<string> dictionary; // Словарь для транслитерации
	vector<string> ErrorsList; // Массив строк с ошибками

	bool textIsValid = !readText(textPath, text, ErrorsList); // Чтение текста

	bool dictionaryIsValid = !readDictionary(dictionaryPath, dictionary, ErrorsList); // Чтение словаря

	if(textIsValid && dictionaryIsValid)
		transliterationOfText(text, dictionary, ErrorsList); // Транслитерация текста

	writeFile(text, textPath, ErrorsList); // Вывод результата
}

bool readText(string& textPath, vector<string>& text, vector<string>& ErrorsList)
{
	ifstream fText(textPath); // Считываем файл для записи текста
	if (!fText)
	{
		ErrorsList.push_back("Ошибка открытия файла текста " + textPath + " файл не существует или недостаточно прав доступа для его открытия");
		return false;
	}
	else
	{
		string tmp; // Временная переменная для хранения текущей строки
		while (getline(fText, tmp))
		{
			text.push_back(tmp);
		}
	}
	if (text.size() == 0)
		ErrorsList.push_back("Ошибка: Текст не введен");

	return ErrorsList.size() == 0 ? false : true;
}

bool readDictionary(string& dictionaryPath, vector<string>& dictionary, vector<string>& ErrorsList)
{
	ifstream fDict(dictionaryPath); // Открываем файл для записи текста
	if (!fDict)
	{
		ErrorsList.push_back("Ошибка открытия файла словаря " + dictionaryPath + " файл не существует или недостаточно прав доступа для его открытия");
		return false;
	}
	else
	{
		string tmp; // Временная переменная для хранения текущей строки.
		while (getline(fDict, tmp))
		{
			dictionary.push_back(tmp);
		}
	}
	return checkDictionary(dictionary, ErrorsList);
}

bool checkDictionary(vector<string>& dictionary, vector<string>& ErrorsList)
{
	int sizeBefore = ErrorsList.size();

	if (dictionary.size() == 0) // Проверка на пустой словарь
		ErrorsList.push_back("Ошибка: словарь не введен");
	else
	{

		for (int i = 0; i < dictionary.size(); i++)
		{
			/* Проверка на два слова в строке */
			if (count(dictionary.at(i).begin(), dictionary.at(i).end(), ' ') > 1)
				ErrorsList.push_back("Ошибка: в словаре указаны излишние соответствия, в строке " + to_string(i + 1) + " излишние сочетания букв");

			else if (count(dictionary.at(i).begin(), dictionary.at(i).end(), ' ') == 0)
				ErrorsList.push_back("Ошибка: в словаре указаны не все соответствия, в строке " + to_string(i + 1) + " недостаточно сочетаний букв");

			/* Проверка на то, что первый символ буква и русская буква*/
			if (!((dictionary.at(i).at(0) >= 'а' && dictionary.at(i).at(0) <= 'я') || (dictionary.at(i).at(0) >= 'А' && dictionary.at(i).at(0) <= 'Я') || dictionary.at(i).at(0) == 'ё' || dictionary.at(i).at(0) == 'Ё'))
			{
				string tmp(1, dictionary.at(i).at(0));
				ErrorsList.push_back("Ошибка: в словаре в строке " + to_string(i + 1) + " не может быть определён '" + tmp + "'");
			}

			/* Проверка на все символы принадлежат 'а-я' 'a-z' */
			for (int j = 0; j < dictionary.at(i).size(); j++)
			{
				char currSymb = dictionary.at(i).at(j);
				bool tnp = (currSymb >= 'А' && currSymb <= 'Я');
				if (!((currSymb >= 'а' && currSymb <= 'я') || (currSymb >= 'А' && currSymb <= 'Я') || currSymb == 'ё' || currSymb == 'Ё' || (currSymb >= 'a' && currSymb <= 'z') || (currSymb >= 'A' && currSymb <= 'Z') || currSymb == ' '))
				{
					string tmp(1, dictionary.at(i).at(j));
					ErrorsList.push_back("Ошибка: в словаре в строке " + to_string(i + 1) + " встретился неизвестный символ '" + tmp + "'");
				}
			}
			if (dictionary.at(i).size() > 2)
			{
				int size = dictionary.at(i).size() - 2; //  Длина символа в словаре
				string dictSymbol = dictionary.at(i).substr(2, size); // Символ в словаре
				for (int j = 0; j < dictionary.size(); j++)
					if (i != j && dictionary.at(j).size() > 2)
					{
						int currSize = dictionary.at(j).size() - 2; //  Длина символа в словаре
						string currSymbol = dictionary.at(j).substr(2, currSize); // Символ в словаре
						if (!dictSymbol.compare(currSymbol))
							ErrorsList.push_back("Ошибка: буква \'" + currSymbol + "\' в строке " + to_string(i + 1) + " не может быть точно определена.");
					}
			}
		}
	}
	int sizeAfter = ErrorsList.size();

	return sizeBefore != sizeAfter;
}

bool transliterationOfText(vector<string>& text, vector<string>& dictionary, vector<string>& ErrorsList)
{
	bool notFound; // Переведён ли текущий символ

	for (int i = 0; i < text.size(); i++) // Для каждой строки
	{
		for (int k = 0; k < text.at(i).size(); k++) // Для каждого символа строки
		{
			string str = text.at(i); // Обновить текущую строку
			notFound = true; // Считать, что текущий символ не найден (не переведен)

			for (int j = 0; j < dictionary.size() && notFound; j++) // Для каждой строки словаря
			{
				int size = dictionary.at(j).size() - 2; //  Длина символа в словаре
				string dictSymbol = dictionary.at(j).substr(2, size); // Символ в словаре
				string replaceSymbol = dictionary.at(j).substr(0, 1); // Заменяемый символ

				if (str.size() - k - size >= 0) // Если текущая буква умещается в строке
				{

					string symbol = str.substr(k, size); // Текущий символ в тексте

					if (!symbol.compare(dictSymbol)) // Если текущая заглавная буква в тексте совпадает с буквой из словаря
					{
						text.at(i).replace(k, size, replaceSymbol); // Поменять их
						notFound = false; // Считать, что буква заменена
					}

					symbol.at(0) = tolower(symbol.at(0)); // Перевести текущий символ в нижний регистр
					dictSymbol.at(0) = tolower(dictSymbol.at(0)); // Перевсти символ из словаря в нижний регистр

					if (replaceSymbol.at(0) != 'Ё') // Перевести в нижний регистр заменяемый символ
						replaceSymbol.at(0) = replaceSymbol.at(0) + 32;
					else
						replaceSymbol.at(0) = 'ё';

					if (!symbol.compare(dictSymbol) && notFound) // Если текущая прописная буква в тексте совпадает с буквой из словаря и она не заглавная
					{
						text.at(i).replace(k, size, replaceSymbol); // Поменять их
						notFound = false; // Считать, что буква заменена
					}

				}
			}
		}
	}
	return checkTransliteration(text, ErrorsList);
}

bool checkTransliteration(vector<string>& text, vector<string>& ErrorsList)
{
	bool isFound = false;
	for (int i = 0; i < text.size(); i++) // Для всех строк текста
	{
		for (int j = 0; j < text.at(i).size(); j++) // Для каждого символа
			if ((text.at(i).at(j) >= 'a' && text.at(i).at(j) <= 'z') || (text.at(i).at(j) >= 'A' && text.at(i).at(j) <= 'Z')) // Если символ из английских символов
			{
				string tmp(1, text.at(i).at(j));
				ErrorsList.push_back("Ошибка: Символ \'" + tmp + "\' не найден");
				isFound = true;
			}
	}
	return isFound;
}

void writeFile(vector<string>& transText, string textPath, vector<string>& ErrorsList)
{
	//ofstream finText(textPath + "RESULT.txt"); // Создаем файл для записи текста
	//finText.close();
	ofstream foutText(textPath + "RESULT.txt"); // Открываем файл для записи текста

	//ofstream finErrors(textPath + "ERRORS.txt"); // Создаем файл для записи ошибок
	//finErrors.close();
	ofstream foutErrors(textPath + "ERRORS.txt"); // Открывем файл для записи ошибок

	if (!foutText) // Если не удалось открыть
	{
		ErrorsList.push_back("Ошибка создания файла файла Result" + textPath + " недостаточно прав для создания файла");
	}
	else
	{
		for (int i = 0; i < transText.size(); i++) // Для каждой строки переведенного текста
		{
			foutText << transText.at(i) << endl; // Записать в файл
		}
		foutText.close(); // закрываем файл
	}
	if (ErrorsList.size() > 0) 
	{
		for (int i = 0; i < ErrorsList.size(); i++) // Для каждой строки ошибок
		{
			foutErrors << ErrorsList.at(i) << endl; // Записать в файл
		}
	}
	foutErrors.close(); // закрываем файл
}

