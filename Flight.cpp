//класс даты и flight
#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "MyDate.h"
#include "Flight.h"
using namespace std;

Flight::Flight()
	{
		string location = "";
		string person = "";
		int flynum = 0;
		int bagplace = 0;
		MyDate execdate;
		int bagweight = 0;
	}

Flight Flight::ChangeFlight(Flight &result)
{
	int n;
	cout << "Выберите один из пунктов для изменения: " << endl;
	cout << "1 - Изменить пункт назначения" << endl;
	cout << "2 - Изменить фамилию пассажира " << endl;
	cout << "3 - Изменить номер рейса" << endl;
	cout << "4 - Изменить количество мест багажа" << endl;
	cout << "5 - Изменить дату полета" << endl;
	cout << "6 - Изменить вес багажа" << endl;
	n = InputNumber(0, 6, "Ваш выбор:");
	switch (n)
	{
	case 1: 
		result.location = InputInformation("Введите новый пункт назначения: ");
		break;
	case 2:
		result.person = InputInformation("Введите фамилию пассажира: ");
		break;
	case 3:
		result.flynum = InputNumber(0, 100, "Введите номер рейса (0 - 100): ");
		break;
	case 4:
		result.bagplace = InputNumber(0, 80, "Введите количество мест багажа (0-80): ");
		break;
	case 5:
		result.execdate.InputDate();
		break;
	case 6:
		result.bagweight = InputNumber(0, 40, "Введите вес багажа (0 - 40): ");
		break;
	default:
		break;

	}
		return result;
}

	// перегруженный оператор равенства
Flight& Flight::operator = (Flight c)
{
		location = c.location;
		person = c.person;
		flynum = c.flynum;
		bagplace = c.bagplace;
		execdate = c.execdate;
		bagweight = c.bagweight;
		return (*this);
}

// функция ввода структуры с консоли
Flight InputScreenFlight()
{
	Flight c;
	c.location = InputInformation("Введите пункт назначения: ");
	c.person = InputInformation("Введите фамилию пассажира: ");
	c.flynum = InputNumber(0, 100, "Введите номер рейса: ");
	c.bagplace = InputNumber(0, 80, "Введите количество мест багажа: ");
	c.execdate.InputDate();
	c.bagweight = InputNumber(0, 40, "Введите вес багажа: ");
	return c;
}

// функция вывода структуры на консоль
void OutputScreenFlight(Flight c)
{
	cout << "Пункт назначения: " << c.location << endl;
	cout << "Фамилия пассажира: " << c.person << endl;
	cout << "Номер рейса: " << c.flynum << endl;
	cout << "Количество мест багажа: " << c.bagplace << endl;
	cout << "Дата: " << c.execdate.ToString() << endl;
	cout << "Вес багажа: " << c.bagweight << endl;
}



string ToString(Flight c, int i)
{
	string result = "Запись № " + to_string(i) + "\n" + "Пункт назначения: " + c.location + "\n" + "Фамилия пассажира: " + c.person + "\n" + "Номер рейса: " + to_string(c.flynum) + "\n" + "Количество мест багажа: " + to_string(c.bagplace) + "\n" + "Дата и время вылета: " + c.execdate.ToString() + "\n" + "Вес багажа: " + to_string(c.bagweight) + "\n";
	return result;
}

////считывание структуры из строки
Flight ReadFromString(ifstream& input)
{
	Flight result;
	string s;
	try
	{
		if (!input.eof())
		{
			getline(input, s);
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Пункт назначения: ";
			result.location = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Фамилия пассажира: ";
			result.person = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Номер рейса: ";
			result.flynum = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Количество мест багажа: ";
			result.bagplace = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Дата и время вылета: ";
			result.execdate = result.execdate.FromString(s.substr(wrd.length(), s.length()));


		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Вес багажа: ";
			result.bagweight = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
}


// поиск равного элемента по выбранному критерию
// typesearch - тип поиска
//1 - по номеру рейса
//2 - по месту
//3 - по дате
bool SearchElement(Flight m, Flight n, int typesearch)
{
	switch (typesearch)
	{
	case 1:
		return (m.flynum == n.flynum);
	case 2:
		return (m.location == n.location);
	case 3:
		return (m.bagweight == n.bagweight);
	case 4:
		return (m.execdate == n.execdate);
	default:
		return false;
	}
}

// ввод критерия поиска в зависимости от выбранного типа 

Flight InputChangeTypeSearch(int typesearch)
{
	Flight result;
	switch (typesearch)
	{
	case 1:
		result.flynum = InputNumber(0, 100, "Введите номер рейса: ");
		return result;
	case 2:
		result.location = InputInformation("Введите пункт назначения: ");
		return result;
	case 3:
		result.bagweight = InputNumber(0, 100, "Введите вес багажа: ");
		return result;
	case 4:
		result.execdate.InputDate();
		return result;
	default:
		return result;
	}
}

// сравнения структур в зависимости от выбранного поля для сортировки

int Sorte(Flight n, Flight m, int typesearch)
{
	switch (typesearch)
	{
	case 1:
		if (n.flynum > m.flynum) return 1;
		else if (n.flynum < m.flynum) return -1;
		else return 0;
	case 2:
		if (n.location > m.location) return 1;
		else if (n.location < m.location) return -1;
		else return 0;
	case 3:
		if (n.bagweight > m.bagweight) return 1;
		else if (n.bagweight < m.bagweight) return -1;
		else return 0;
	case 4:
		if (n.execdate > m.execdate) return 1;
		else if (n.execdate < m.execdate) return -1;
		else return 0;
	default:
		return -2;
	}
}




