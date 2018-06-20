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
using namespace std;

class Flight {
public:
	// пункт назначения
	string location;
	// фамилия пассажира
	string person;
	// номер рейса
	int flynum;
	// место в багаже
	int bagplace;
	// дата и время
	MyDate execdate;
	// вес багажа
	int bagweight;

	// конструктор по умолчанию
	Flight();


	// изменение структуры
	Flight ChangeFlight(Flight &result);

	// перегруженный оператор равенства
	Flight& operator = (Flight c);
};

// функция ввода структуры с консоли
Flight InputScreenFlight();

// функция вывода структуры на консоль
void OutputScreenFlight(Flight c);




//перевод структуры в строку
string ToString(Flight c, int i);

////считывание структуры из строки
Flight ReadFromString(ifstream& input);

// поиск равного элемента по выбранному критерию
// typesearch - тип поиска
//1 - по номеру рейса
//2 - по месту
//3 - по дате
bool SearchElement(Flight m, Flight n, int typesearch);

// ввод критерия поиска в зависимости от выбранного типа 

Flight InputChangeTypeSearch(int typesearch);

// сравнения структур в зависимости от выбранного поля для сортировки

int Sorte(Flight n, Flight m, int typesearch);



