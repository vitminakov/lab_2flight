#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include "HelpUtils.h"


//подтип дата
class MyDate {
private:
	// проверка является ли год високосным
	bool IsLeap(int year);

	// проверка даты на корректность
	bool CorrectDate(int day, int month, int year, string &message);

	// день
	int day;
	// месяц
	int month;
	// год
	int year;
	int hours;
	int minutes;

public:

	// конструктор по умолчанию
	MyDate();

	// ввод даты с консоли
	void InputDate();

	// перевод даты в строку (для последующей записи в файл)
	string ToString();

	// перегруженный оператор равенства
	bool operator == (const MyDate &c);

	// конструктор копирования
	MyDate& operator = (MyDate c);

	// перегруженный оператор больше
	bool operator > (const MyDate &c);

	// перегруженные оператор меньше
	bool operator < (const MyDate &c);

	//извлечение структуры "дата" из строки 
	// Формат:
	// день месяц год
	static MyDate FromString(string str);

};

