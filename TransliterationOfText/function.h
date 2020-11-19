#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

/*!
*\brief ������� ������������� �������
*\param[in] textPath � ���� � ������
*\param[in] dictionaryPath � ���� � �������
*/
void transliteration(string& textPath, string& dictionaryPath);

/*! 
*\brief ������ �������
*\param[in] dictionaryPath � ���� � ����� �������
*\param[in] dictionary � �������
*\param[out] ErrorsList � ������ ����� ������
*\return � ������� ������
*/
bool readDictionary(string& dictionaryPath, vector<string>& dictionary, vector <string>& ErrorsList);

/*!
*\brief �������� ���� �� ���������� ��������� ���� � ������� �������
*\param[in] dictionary � �������
*\param[out] ErrorsList � ������ ����� ������
*\return � ���������� �� ������������� �������
*/
bool checkDictionary(vector<string>& dictionary, vector <string>& ErrorsList);

/*!
*\brief �������� ���� �� ���������� ��������� ���� � ������� �������
*\param[in] textPath � ���� � ����� ������
*\param[in, out] text � ����������, ���������� �����
*\param[out] ErrorsList � ������ ����� ������
*\return � ������� ������
*/
bool readText(string& textPath, vector<string>& text, vector<string>& ErrorsList);

/*!
*\brief �������, ����������������� �����
*\param[in, out] text � ����� ��� ��������������
*\param[in] dictionary � �������
*\param[out] ErrorsList � ������ ����� ������
*\return � ����������� ���������� ��������������
*/
bool transliterationOfText(vector<string>& text, vector<string>& dictionary, vector<string>& ErrorsList);

/*!
*\brief ���������, ��� �� ������� ���� ����������
*\param[in] text � ����� ��� ��������
*\param[out] ErrorsList � ������ ����� ������
*\return � ����������� ���������� ��������������
*/
bool checkTransliteration(vector<string>& text, vector<string>& ErrorsList);

/*!
*\brief �������, ��������� ���� ��� ������ �������������������� ������
*\param[in] transText � ������������������� �����
*\param[in] textPath - ��� ��������� �����
*\param[in] ErrorsList � ������ ����� ������
*/
void writeFile(vector<string>& transText, string textPath, vector<string>& ErrorsList);
