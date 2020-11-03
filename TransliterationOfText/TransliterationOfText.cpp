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

	transliterationOfText(text, dictionary); // Транслитерация текста

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

bool checkRepetition(vector<string>& dictionary, vector<string>& ErrorsList)
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

bool transliterationOfText(vector<string>& text, vector<string>& dictionary)
{
	bool notFound; // Переведён ли текущий символ

	for (int i = 0; i < text.size(); i++) // Для каждой строки
	{
		string str = text.at(i); // Текущая строка

		for (int k = 0; k < text.at(i).size(); k++) // Для каждого символа строки
		{
			notFound = true; // Считать, что текущий символ не найден (не переведен)

			for (int j = 0; j < dictionary.size() && notFound; j++) // Для каждой строки словаря
			{
				int size = dictionary.at(j).size() - 2; //  Длина символа в словаре
				string dictSymbol = dictionary.at(j).substr(2, size); // Символ в словаре
				string replaceSymbol = dictionary.at(j).substr(0, 1); // Заменяемый символ
				if (str.size() - k - size >= 0) // Если текущая буква умещается в строке
				{

					string symbol = str.substr(k, size); // Текущий символ в тексте

					if (!symbol.compare(dictSymbol)) // Если текущая буква в тексте совпадает с буквой из словаря
					{
						text.at(i).replace(k, size, replaceSymbol); // Поменять их
						notFound = false; // Считать, что буква заменена
					}
				}
			}
		}
	}
	return true;
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

