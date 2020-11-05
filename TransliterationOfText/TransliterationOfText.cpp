﻿#include <iostream>
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
		/*cout << "Input text path" << endl;
		cin >> textPath;
		cout << "\nInput dictionary path" << endl;
		cin >> dictionaryPath;*/
		textPath = "text.txt";
		dictionaryPath = "symbols.txt";
	}

	// TODO: Выделить отдельную общую функцию под нижележащие строки
	vector<string> text; // Исходный текст для транслитерации
	vector<string> dictionary; // Словарь для транслитерации
	vector<string> ErrorsList; // Массив строк с ошибками

	readText(textPath, text, ErrorsList); // Чтение текста

	readDictionary(dictionaryPath, dictionary, ErrorsList); // Чтение словаря

	transliterationOfText(text, dictionary, ErrorsList); // Транслитерация текста

	writeFile(text, textPath, ErrorsList); // Вывод результата

	return 0;
}

bool readDictionary(string& dictionaryPath, vector<string>& dictionary, vector<string>& ErrorsList)
{
	ifstream fDict(dictionaryPath); // Открываем файл для записи текста
	if (!fDict)
	{
		ErrorsList.push_back("Ошибка открытия файла словаря" + dictionaryPath + " файл не существует или недостаточно прав доступа для его открытия");
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
	return true;
}

bool checkDictionary(vector<string>& dictionary, vector<string>& ErrorsList)
{
	return false;
}

bool readText(string& textPath, vector<string>& text, vector<string>& ErrorsList)
{
	ifstream fText(textPath); // Считываем файл для записи текста
	if (!fText)
	{
		ErrorsList.push_back("Ошибка открытия файла текста" + textPath + " файл не существует или недостаточно прав доступа для его открытия");
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
	return true;
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

					if(!symbol.compare(dictSymbol) && notFound) // Если текущая прописная буква в тексте совпадает с буквой из словаря и она не заглавная
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
	bool isFound = true;
	for (int i = 0; i < text.size(); i++) // Для всех строк текста
	{
		for (int j = 0; j < text.at(i).size(); j++) // Для каждого символа
			if ((text.at(i).at(j) >= 'a' && text.at(i).at(j) <= 'z') || (text.at(i).at(j) >= 'A' && text.at(i).at(j) <= 'Z')) // Если символ из английских символов
			{
				string tmp(1, text.at(i).at(j));
				ErrorsList.push_back("Символ \'" + tmp + "\' не найден");
				isFound = false;
			}
	}
	return isFound;
}

void writeFile(vector<string>& transText, string textPath, vector<string>& ErrorsList)
{
	ofstream finText("RESULT" + textPath); // Создаем файл для записи текста
	finText.close();
	ofstream foutText("RESULT" + textPath); // Открываем файл для записи текста

	ofstream finErrors("ERRORS" + textPath); // Создаем файл для записи ошибок
	finErrors.close();
	ofstream foutErrors("ERRORS" + textPath); // Открывем файл для записи ошибок

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
	for (int i = 0; i < ErrorsList.size(); i++) // Для каждой строки ошибок
	{
		foutText << ErrorsList.at(i) << endl; // Записать в файл
	}
	foutErrors.close(); // закрываем файл
}

