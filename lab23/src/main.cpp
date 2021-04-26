#include "classes.h"

/**
*@mainpage
*# Загальне завдання
*1. **Завдання**
*	З розділу "Розрахункове завдання" взяти галузь за номером свого варіанту та зробити завдання.
*
*# Опис програми
*2. *Опис*
* 	Програма складається з семи функцій та двох классів
*@author Steghniy B.
*@date 26-apr-2021
*/

/**
* @file main.cpp
* @author Steghniy B.
* @return 0
* @version 0.1 
* @date 26-apr-2021
*/


using namespace std;

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "ru");
	
	int n,n1,n2,choice;
	cout << " Сколько элементов будет в массиве?: " << endl;
	cin >> n;

	
	Fighter_Arr MyMass(n);

	MyMass.FillArr();
	
	Fighter addMass;

	while (1) {
		cout << " [1] Добавить элемент в массив \n [2] Удалить элемент из массива \n [3] Получить элемент по индексу \n [4] Вывести содержимое массива \n [5] Найти количество представителей кланов \n [6] Выйти \n Введите критерий: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			MyMass.AddFighter(addMass);
			break;
		case 2:
			cout << " Введите индекс для удаления: ";
			cin >> n1;
			cout << endl;
			MyMass.DeleteFighter(n1);
			break;
		case 3:
			cout << "Введите какой элемент получить по индексу: ";
			cin >> n2;
			MyMass.GetFighter(n2);
			break;
		case 4:
			MyMass.PrintMass();
			break;
		case 5:
			MyMass.SearchClan();
			break;
		case 6:
			return 0;
		}
	}


	return 0;
}

