#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

/*
* „тение словар€
* \param[in] dictionaryPath Ц ѕуть к файлу словар€
* \param[in] dictionary Ц словарь
* \param[out] ErrorsList Ц массив кодов ошибок
* \return Ц наличие ошибки
*/
bool readDictionary(string& dictionaryPath, vector<string>& dictionary, vector <string>& ErrorsList);

/*
* ѕроверка есть ли одинаковые сочетани€ букв в строках словар€
* \param[in] dictionary Ц словарь
* \param[in][out] ErrorsList Ц массив кодов ошибок
* \return Ц существуют ли повтор€ющиес€ символы
*/
bool checkRepetition(vector<string>& dictionary, vector <string>& ErrorsList);

/*
* ѕроверка есть ли одинаковые сочетани€ букв в строках словар€
* \param[in] textPath Ц путь к файлу текста
* \param[in][out] text Ц переменна€, содержаща€ текст
* \param[out] ErrorsList Ц массив кодов ошибок
* \return Ц наличие ошибки
*/
bool readText(string& textPath, vector<string>& text, vector<string>& ErrorsList);

/*
* ‘ункци€, транслитерирующа€ текст
* \param[in] text Ц текст дл€ транслитерации
* \param[in] dictionary Ц словарь
* \return Ц возможность произвести транслитерацию
*/
bool transliterationOfText(vector<string>& text, vector<string>& dictionary);

/*
* ‘ункци€, создающа€ файл дл€ записи транслитерированного текста
* \param[in] transText Ц транслитерированный текст
* \param[in] textPath - им€ выходного файла
* \param[out] ErrorsList Ц массив кодов ошибок
*/
void writeFile(vector<string>& transText, string textPath, vector<string>& ErrorsList);
