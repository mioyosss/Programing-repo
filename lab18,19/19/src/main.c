#include "lib.h"

/**
*@mainpage
*# Загальне завдання
*1. **Завдання**
*	З розділу "Розрахункове завдання" взяти галузь за номером свого варіанту та зробити завдання.
*
*# Опис програми
*2. *Опис*
* 	Програма складається з семи функцій та структури
*@author Steghniy B.
*@date 27-mar-2021
*/

/**
* @file main.c
* @author Steghniy B.
* @return 0
* @version 0.1 
* @date 27-mar-2021
*/


int main()
{
	srand(time(NULL));

	// Открытые и создание файлов
	FILE *read = fopen("/home/mioyos/Programing-repo/test/FIGHTERS.txt", "r");
	FILE *write = fopen("result","w");
	
	// Проверка открытия файлов
	if (read != NULL){
		printf("Файл для чтения успешно открыт!\n\n");
		} else {
		printf("Файл для чтения не был открыт. Попробуйте ввести правильный путь к файлу \n\n");
		exit(1);
		}
	if (write != NULL){
		printf("Файл для записи успешно создан!\n\n");
		} else {
		printf("Файл для записи не был создан\n\n");
		exit(1);	
	}
	
	// Определяем количество узлов в спике
	int N;
	fscanf(read,"%d", &N);
	// Создаем "голову" нашего списка
	list_type* head = create_list(N);	
	// Чтение и запись элементов в список
	read_from_file(head, read, N);
	// Запись списка в файл
	write_to_file(head, write, N);
	// Вывод списка на экран
	output(head);
	// Нахождение элементов по заданому критерию
	find_object(head, N);
	
	push_to_end(head, N);
	return 0;	
}									

