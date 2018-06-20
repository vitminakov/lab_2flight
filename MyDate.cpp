#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "MyDate.h"

//подтип дата
// проверка €вл€етс€ ли год високосным
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
		message = "Ќеверное кол-во дней в феврале!";
		return false;
	}
	//кол-во дней в мес€це
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			message = "Ќеверное кол-во дней в мес€це!";
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
	bool correct_date = true; // корректна ли введенна€ дата
	string message = "";  // сообщение о причине ошибки
	do
	{
		if (!correct_date)
			cout << message << endl;
		day = InputNumber(1, 31, "¬вод даты:\n¬ведите день (1-31): ");
		month = InputNumber(1, 12, "¬ведите номер мес€ца (1-12): ");
		year = InputNumber(1970, 2100, "¬ведите год (1970-2100):");
		hours = InputNumber(0, 23, "¬вод времени:\n¬ведите часы (0-23):");
		minutes = InputNumber(0, 59, "¬ведите минуты (0-59):");
		correct_date = CorrectDate(day, month, year, message);
	} while (!correct_date);  // повтор€ть ввод пока не корректна€ дата
}

// перевод даты в строку (дл€ последующей записи в файл)
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

// конструктор копировани€
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
// ‘ормат:
// день мес€ц год
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
		cout << "ќшибка записи в файл!" << endl;
	}
	return result;
}