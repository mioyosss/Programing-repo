#include "lib.h"

/**
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Steghniy B.
 * @date 08-mar-2021
 * @version 0.1
 */

char* insert(char *s1, char *s2, int pos)
{
	char *result = (char*)malloc(strlen(s1)+strlen(s2)+1);
	/* Копируем определнное количество байт с первого слова в результирующую строку */
	memcpy(result, s1, pos);
	// printf("%s\n", result);
	/* Копируем первое слово и вставляем в результирующую строку  */
	memcpy(result + pos, s2, strlen(s2));
	/* Обьеденяем результирующую строку с концом первой строки */
	memcpy(result + pos + strlen(s2), s1 + pos, strlen(s1));

	printf("\n ╔════════════════════════════╗\n ║        Задания 1-2         ║ \n ╠════════════════════════════╣ \n ║ Вставка: %s\n ║                            ║\n", result);

	return result;
	
}

char* cutout(char *s1, int start, int end)
{
	char *result = (char*)malloc(strlen(s1)+1);
	/* Копируем в резултирующую строку символы до "вырезания" */
	memcpy(result, s1, start-1);
	/* Обьеденияем начало строки и ее конец после "вырезания" */
	memcpy(result + start - 1, s1 + end, strlen(s1));

	printf(" ║ Вырезание: %s\n ╚════════════════════════════╝ \n\n\n", result);

	return result;

}

void* filling(fighter *fighter_mass, int N)
{
	for(int i = 0; i < N; i++)
	{
		fighter_mass[i].human = rand() % 2;
		fighter_mass[i].gender = rand() % 2;
		sprintf(fighter_mass[i].name, "Боец №%d", rand() % 10);
		fighter_mass[i].health = rand() % 10;
		fighter_mass[i].power = rand() % 10;
		fighter_mass[i].bonus = rand() % 4;
		fighter_mass[i].clancolor = rand() % 3;
	}
}

void add_struct( fighter * fighter_mass, int n)
{
	/* Задаем массив куда будет добавлять стркутуру */
	fighter add_mass[1];
	/* Обращаяемся к элементам структуры по указателю */
	add_mass->human = rand() % 2;
	add_mass->gender = rand() % 2;
	sprintf(add_mass->name, "Боец №%d", rand() % 10);
	add_mass->health = rand() % 10;
	add_mass->power = rand() % 10;
	add_mass->bonus = rand() % 4;
	add_mass->clancolor = rand() % 3;
	/* Копируем из массива add_mass в массив fighter_mass на третью позицию */
	memmove(fighter_mass+n, add_mass, sizeof(fighter));
}

void delete_struct(fighter * fighter_mass, int n, int struct_to_delete)
{
   	/* Заполняем пробелами стркутуру */
	memset(fighter_mass+struct_to_delete, ' ', sizeof(fighter));

	for(int i=struct_to_delete;i<n;i++)
    	{
        	memmove(fighter_mass+i, fighter_mass+i+1, sizeof(fighter));
    	}
}
