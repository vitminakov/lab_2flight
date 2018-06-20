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
using namespace std;

//ввод числа
int InputNumber(int min, int max, string message);
//ввод строки
string InputInformation(string messge);
//проверки на корректность введенных символов
bool CorrectSymbol(char c);
bool CorrectName(string name);
//ввод имени файла
string InputFileName();




