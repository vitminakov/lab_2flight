//работа с векторами и операции над ними
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Flight.h"
#include "HelpUtils.h"
#include "MyDate.h"
using namespace std;


template <class Type>
class Task {
private:
	// сортировка по заданному критерию 
	void ShellSort(int n, int typ, int(*Compare)(Type, Type, int))
	{
		int i, j, step;
		Type tmp;
		for (step = n / 2; step > 0; step /= 2)  
			for (i = step; i < n; i++)
			{
				tmp = vect[i];
				for (j = i; j >= step; j -= step)
				{
					if ((Compare(tmp, vect[j - step], typ) == -1))
						vect[j] = vect[j - step];
					else
						break;
				}
				vect[j] = tmp;
			}

	}
	// бинарный поиск
	int BinarySearchElement(int left, int right, int typesearch, Type d, int(*Compare)(Type, Type, int))
	{
		int midd = 0;
		while (1)
		{
			midd = (left + right) / 2;

			if (Compare(d, vect[midd], typesearch) == -1)// если искомое больше значения в ячейке
				right = midd - 1;				// смещаем правую границу поиска
			else if (Compare(d, vect[midd], typesearch) == 1)  // если искомое меньше значения в ячейке
				left = midd + 1;					// смещаем левую границу поиска
			else                       // иначе (значения равны)
				return midd;           // функция возвращает индекс ячейки

			if (left > right)          // если границы сомкнулись 
				return -1;
		}
	}
public:
	vector<Type> vect;
	Task() {}
	~Task() {}

	// удаление элемента
	void Remove( int numb)
	{
		if (numb != 0)
			vect.erase(vect.begin() + numb-1);
	}
	
	// добавление элемента
	void Add(Type &elem)
	{
		vect.push_back(elem);
	}

	//размер вектора
	int size()
	{
		return vect.size();
	}

	// проверка на пустоту
	bool Is_empty()
	{
		return (vect.size() == 0);
	}

	// вывод в файл
	// void(*f) (Type) - указатель на функцию, которая записывает одну структуру в файл  
	void OutputFile(vector<Type> items,string (*f)(Type,int))
	{
		string newfname = InputFileName();
		ofstream fout(newfname);
		if (fout)
		{
			vector<Type>::const_iterator pos;
			int count = 1;
			for (pos = items.begin(); pos != items.end(); ++pos)
			{
				fout << f(*pos,count) << ' ';
				count++;
			}
			cout << endl << "Файл заполнен!" << endl;
			fout.close();
		}
		else
		{
			cout << "Файл не заполнен!" << endl;
		}
	}

	// вывод на экран
	// void(*f) (Type) - указатель на функцию, которая считывает одну структуру на экран  
	void OutputScreen(vector<Type> items, void (*f) (Type))
	{
		vector<Type>::const_iterator pos;
		int count = 1;
		for (pos = items.begin(); pos != items.end(); ++pos)
		{
			cout << "Запись № " << count << endl;
			f(*pos);
			++count;
			cout << endl;
		}
	}

	// ввод из файла
	// Type(*f)(ifstream&) - указатель на функцию, которая считывает одну структуру из файла 
	bool ReadFromFile(Type(*f)(ifstream&))
	{
		string newfname = InputFileName();
		std::ifstream input;

		input.open(newfname);

		if (!input)
		{
			cout << "Не удалось открыть файл" << endl;
			return false;
		}
		else
		{
			while (!input.eof())
			{
				vect.push_back(f(input));
			}
			vect.erase(vect.begin() + vect.size() - 1);

			input.close();
			return true;
		}
	}

	// ввод с экрана
	//Type(*f)() - указатель на функцию, которая вводит одну структуру с консоли
	void ReadFromScreen(Type (*f)())
	{
		int n;
		Type elem;
		do
		{
			vect.push_back(f());
			n = InputNumber(0, 1, "Вы хотите добавить элемент? (1 - да, 0 - нет)\nВаш выбор: ");
		} while (n != 0);
	}

	// линейный поиск
	// bool(*Equal)(Type, Type, int) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим по typesearch
	vector<Type> LinearySearch(Type search_elem,bool(*Equal)(Type,Type, int),int typesearch)
	{
		vector<Type> NewVect;
		for (auto iter = vect.begin(); iter != vect.end(); iter++)
		{
			if (Equal(search_elem,*iter, typesearch))
				NewVect.push_back(*iter);

		}

		return NewVect;
	}

	// бинарный поиск
	vector<Type> BinarySearch( int typesearch, Type find_element, int(*Compare)(Type, Type, int), bool(*Equal)(Type, Type, int))
	{
		vector<Type> NewVect;
		ShellSort(vect.size(), typesearch, Compare);
		int left = 0;
		int right = vect.size();
		int index;
	    if  ((index = BinarySearchElement(left, right-1,typesearch,find_element,Compare)) != -1)
		{
			NewVect.push_back(vect[index]);
			int first_index = index;
			while ((++index<right)&&Equal(vect[index], find_element, typesearch))
				NewVect.push_back(vect[index]);
			while ((--first_index >= 0)&&Equal(vect[first_index], find_element, typesearch))
				NewVect.push_back(vect[first_index]);
		}
		return NewVect;
	}
};