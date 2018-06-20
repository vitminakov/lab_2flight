#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "MyDate.h"

//подтип дата
// проверка является ли год високосным
bool MyDate::IsLeap(int year)
{
	if (year % 4)
		return false;
	if (year % 100)
		return true;
	return !(year % 400);
}

// проверка даты на корректность
bool MyDate::CorrectDate(int day, int month, int year, string &message) {

	// если год вискосный                            если не високосный
	if ((month == 2 && day > 29 && IsLeap(year)) || (month == 2 && day > 28 && !IsLeap(year)))
	{
		message = "Неверное кол-во дней в феврале!";
		return false;
	}
	//кол-во дней в месяце
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			message = "Неверное кол-во дней в месяце!";
			return false;
		}
	}
	return true;
}

// конструктор по умолчанию
MyDate::MyDate()
{
	int day = 1;
	int month = 1;
	int year = 1970;
}

// ввод даты с консоли
void MyDate::InputDate()
{
	bool correct_date = true; // корректна ли введенная дата
	string message = "";  // сообщение о причине ошибки
	do
	{
		if (!correct_date)
			cout << message << endl;
		day = InputNumber(1, 31, "Ввод даты:\nВведите день (1-31): ");
		month = InputNumber(1, 12, "Введите номер месяца (1-12): ");
		year = InputNumber(1970, 2100, "Введите год (1970-2100):");
		hours = InputNumber(0, 23, "Ввод времени:\nВведите часы (0-23):");
		minutes = InputNumber(0, 59, "Введите минуты (0-59):");
		correct_date = CorrectDate(day, month, year, message);
	} while (!correct_date);  // повторять ввод пока не корректная дата
}

// перевод даты в строку (для последующей записи в файл)
string MyDate::ToString()
{
	return (to_string(day) + ' ' + to_string(month) + ' ' +
		to_string(year) + ' ' + to_string(hours) + ':' + to_string(minutes));
}

// перегруженный оператор равенства
bool MyDate::operator == (const MyDate &c)
{
	return ((day == c.day) && (month == c.month) && (year == c.year) && (hours = c.hours) && (minutes = c.minutes));
}

// конструктор копирования
MyDate& MyDate::operator = (MyDate c)
{
	day = c.day;
	month = c.month;
	year = c.year;
	hours = c.hours;
	minutes = c.minutes;

	return (*this);
}

// перегруженный оператор больше
bool MyDate::operator > (const MyDate &c)
{
	return ((year > c.year) || ((year == c.year) && (month > c.month)) || ((year == c.year) && (month == c.month) && (day>c.day)));
}

// перегруженные оператор меньше
bool MyDate::operator < (const MyDate &c)
{
	return ((year < c.year) || ((year == c.year) && (month < c.month)) || ((year == c.year) && (month == c.month) && (day<c.day)));
}

//извлечение структуры "дата" из строки 
// Формат:
// день месяц год
MyDate MyDate::FromString(string str)
{
	MyDate result;
	try
	{
		istringstream is(str);
		string s;
		if (getline(is, s, ' '))
			result.day = atoi(s.c_str());
		if (getline(is, s, ' '))
			result.month = atoi(s.c_str());
		if (getline(is, s, ' '))
			result.year = atoi(s.c_str());
		if (getline(is, s, ':'))
			result.hours = atoi(s.c_str());
		if (getline(is, s, ' '))
			result.minutes = atoi(s.c_str());
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
}