#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

/*
* ������ �������
* \param[in] dictionaryPath � ���� � ����� �������
* \param[in] dictionary � �������
* \param[out] ErrorsList � ������ ����� ������
* \return � ������� ������
*/
bool readDictionary(string& dictionaryPath, vector<string>& dictionary, vector <string>& ErrorsList);

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
* \param[out] ErrorsList � ������ ����� ������
* \return � ������� ������
*/
bool readText(string& textPath, vector<string>& text, vector<string>& ErrorsList);

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
* \param[in] textPath - ��� ��������� �����
* \param[out] ErrorsList � ������ ����� ������
*/
void writeFile(vector<string>& transText, string textPath, vector<string>& ErrorsList);
