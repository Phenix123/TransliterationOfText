#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

/*
* ������ �������
* \param[in] dictionaryPath � ���� � ����� �������
* \param[in] dictionary � �������
* \param[out] ErrorsList � ������ ����� ������
* \return � ������� ������
*/
bool readDictionary(string dictionaryPath, vector<string> dictionary, vector <string> ErrorsList);

/*
* �������� ���� �� ���������� ��������� ���� � ������� �������
* \param[in] dictionary � �������
* \param[in][out] ErrorsList � ������ ����� ������
* \return � ���������� �� ������������� �������
*/
bool checkRepetition(vector<string>& dictionary, vector <string>& ErrorsList);

/*
* �������� ���� �� ���������� ��������� ���� � ������� �������
* \param[in] textPath � ���� � ����� ������
* \param[in][out] text � ����������, ���������� �����
*/
void readText(vector<string>& textPath, vector<string>& text);

/*
* �������, ����������������� �����
* \param[in] text � ����� ��� ��������������
* \param[in] dictionary � �������
* \return � ����������� ���������� ��������������
*/
bool transliterationOfText(vector<string>& text, vector<string>& dictionary);

/*
* �������, ��������� ���� ��� ������ �������������������� ������
* \param[in] transText � ������������������� �����
*/
void writeFile(vector<string>& transText);
