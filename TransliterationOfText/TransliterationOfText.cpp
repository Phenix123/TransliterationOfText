#include <iostream>
#include "function.h"
#pragma warning(disable:4018)
int main(int argc, char* argv[])
{
    if (argc > 1) 
    {
        // console mode
    }
    else 
    {
        // some code
    }
}

bool readDictionary(string& dictionaryPath, vector<string>& dictionary, vector<string>& ErrorsList)
{
    return true;
}

bool checkRepetition(vector<string>& dictionary, vector<string>& ErrorsList)
{
    return false;
}

void readText(vector<string>& textPath, vector<string>& text)
{
}

bool transliterationOfText(vector<string> &text, vector<string>& dictionary)
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

void writeFile(vector<string>& transText)
{
}

