/* №10 Запись о багаже пассажира авиарейса содержит поля : номер рейса, дата и время вылета, 
пункт назначения, фамилия пассажира, количество мест багажа, суммарный вес багажа.
Поиск по номеру рейса, дате вылета, пункту назначения, весу багажа.Подсчет общего веса багажа. */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <Windows.h>
#include "HelpUtils.h"
#include "Operation.h"
#include "Flight.h"
using namespace std;


int Menu()
{
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Добавить элемент" << endl;
	cout << "2 - Удалить элемент" << endl;
	cout << "3 - Изменить элемент" << endl;
	cout << "4 - Вывод на экран" << endl;
	cout << "5 - Сохранить в файл " << endl;
	cout << "6 - Линейный поиск" << endl;
	cout << "7 - Двоичный поиск" << endl;
	cout << "--------------------" << endl;
	cout << "8 - Вывести подможество на экран" << endl;
	cout << "9 - Сохранить подмножество в файл" << endl;
	cout << "0 - Выход" << endl;
	int n = InputNumber(0, 9, "Ваш выбор: ");
	cout << "\n";
	return n;
}

bool ChangeInputData()
{
	Task<Flight> task;
	bool change = true;
	cout << "Выберите один из пунктов меню: " << endl;
	cout << "1 - Заполнение контейнера с консоли" << endl;
	cout << "2 - Заполнение контейнера из файла " << endl;
	cout << "0 - Выход" << endl;
	int changemenu = InputNumber(0, 2, "Ваш выбор: ");
	switch (changemenu)
	{
	case 1:
		task.ReadFromScreen(InputScreenFlight);
		break;

	case 2:
		change=task.ReadFromFile(ReadFromString);
		break;

	default:
		change = false;
		break;
	}
	if (change)
			{
				Flight elem;
				vector<Flight> subset;
				Flight search_elem;
				int numb;
				while (1)
				{
					int n = Menu();
					switch (n)
					{
					case 1:
						task.Add(InputScreenFlight());
						break;
		
					case 2:
						task.OutputScreen(task.vect, OutputScreenFlight);
						cout << "Всего - " << task.size() << endl;
						task.Remove(InputNumber(0, task.size(), "\nВведите номер удаляемого эл-та (0 - если передумали удалять):"));
						break;
		
					case 3:
						task.OutputScreen(task.vect, OutputScreenFlight);
						cout << "Всего - " << task.size() << endl;
						numb = InputNumber(0, task.size(), "\nВведите номер изменяемого эл-та (0 - если передумали изменять): ");
						if (numb != 0)
						{ 
							task.vect[numb-1] = elem.ChangeFlight(task.vect[numb-1]);
							cout << "Данные изменены!" << endl;
						}
						break;
		
					case 4:
						task.OutputScreen(task.vect,OutputScreenFlight);
						break;
		
					case 5:
						task.OutputFile(task.vect,ToString);
						break;

					case 6:
						numb = InputNumber(1, 4, "Выберите тип поиска:\n 1 - по номеру рейса\n 2 - по пункту назначения\n 3 - по весу багажа\n 4 - по дате и времени вылета \nВаш выбор: ");
						search_elem = InputChangeTypeSearch(numb);
						subset = task.LinearySearch(search_elem,SearchElement,numb);
						if (subset.size() != 0)
							task.OutputScreen(subset, OutputScreenFlight);
						else
							cout << "Элементы не найдены" << endl;
						break;
		
					case 7:
						numb = InputNumber(1, 3, "Выберите тип поиска:\n 1 - по номеру рейса\n 2 - по пункту назначения\n 3 - по весу багажа\n 4 - по дате и времени вылета \nВаш выбор: ");
						search_elem = InputChangeTypeSearch(numb);
						subset = task.BinarySearch(numb,search_elem, Sorte,SearchElement);
						if (subset.size() != 0)
							task.OutputScreen(subset, OutputScreenFlight);
						else
							cout << "Элементы не найдены" << endl;
						break;
		
					case 8:
						task.OutputScreen(subset,OutputScreenFlight);
						break;
		
					case 9:
						task.OutputFile(subset,ToString);
						break;

		
					default:
						cout << "Выход " << endl; exit(0);
						break;
		
					}
				}
			}
			system("pause");
}

void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	ChangeInputData();
}