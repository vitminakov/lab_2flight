//ввод и проверки
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "HelpUtils.h"
using namespace std;

int InputNumber(int min, int max, string message)
{
	int n;
	while (true) {
		cout << message;
		cin >> n;
		if (!cin) {
			cout << "Неверный ввод! Попробуйте снова\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else {
			if (n >= min && n <= max) {
				break;
			}
			else {
				cout << "Некорректно, введите значение в диапазоне от " << min << " до " << max << endl;
				continue;
			}
		}
	}
	return n;
}





// ввод информации
string InputInformation(string messge)
{
	string a;
	cout << messge;
	cin >> a;
	return a;
}

// проверка символа на корректность в имени файла
bool CorrectSymbol(char c)
{
	switch (c)
	{
	case '.':
	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
	case '/':
		return false;
	default:
		return true;
	}
}


// проверка имени файла на коректность
bool CorrectName(string name)
{
	int i = 0;
	bool goodsm = true;
	for (int i = 0; (i < name.length() && goodsm); i++)
		goodsm = CorrectSymbol(name[i]);
	return goodsm;
}

// ввод имени файла
string InputFileName()
{

	string filename;
	do
	{
		cout << "Введите имя файла (без расширения, имя свыше 35 символов будет обрезано):  ";
		cin >> filename;
		if (filename.length() > 35)
			filename.erase(filename.begin(), filename.begin() + 35);
		if (CorrectName(filename))
		{
			filename = filename + ".txt";
			break;
		}
		else
			cout << "Неверное имя файла\n";
	} while (true);

	return filename;
}




