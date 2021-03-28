#include "lib.h"

/**
*@mainpage
*# Загальне завдання
*1. **Завдання**
*	З розділу "Розрахункове завдання" взяти галузь за номером свого варіанту та зробити завдання.
*
*# Опис програми
*2. *Опис*
* 	Програма складається з пяти функцій та структури
*@author Steghniy B.
*@date 08-mar-2021
*/

/**
* @file main.c
* @author Steghniy B.
* @return 0
* @version 0.1 
* @date 08-mar-2021
*/

#define N 3
int main()
{
	clock_t begin = clock();
	srand(time(NULL));
	
	char str1[50];
	printf("\n Введите первую строку: ");
	scanf("%s", &str1);
	char *s1 = (char *)malloc(sizeof(char));
	s1 = &str1;

	char str2[50];
	printf(" Введите вторую строку: ");
	scanf("%s",&str2);
	char *s2 = (char *)malloc(sizeof(char));
	s2 = &str2;
 	
 	int pos;
 	int start;
 	int end;
 	printf("\n Введите позицию в рядке для вставки: ");
 	scanf("%d", &pos);
 	printf("\n Введите начальную позицию в рядке для вырезки: ");
 	scanf("%d", &start);
 	printf(" Введите конечную позицию в рядке для вырезки: ");
 	scanf("%d", &end);
	insert(s1, s2, pos);
	
	cutout(s1, start, end);
	
	fighter *fighter_mass = (fighter*)malloc(sizeof(fighter)*N);
	
	filling((fighter*)fighter_mass, N);
	
		printf(" ╔════════════════════════════╗\n ║        Задания 3-4         ║ \n ╠════════════════════════════╣\n ║ 1. Добавить одну структуру ║ \n ║ 2. Удалить одну структуру  ║\n ╚════════════════════════════╝\n");
		
	int criterion = 0;
	printf("   Введите критерий: ");
	scanf("%d", &criterion);
	printf("\n");

	if ( criterion == 1 )
	{
		add_struct((fighter *)fighter_mass, N);
		for( int i = 0; i < N + 1; i++)
		{
				printf(" ╔═══════════════════════════════════╗ \n");	
			if(fighter_mass[i].human == yes)
				printf(" ║ Боец - человек: да                ║\n");
			if(fighter_mass[i].human == no)
				printf(" ║ Боец - человек: нет               ║\n");
	
			if(fighter_mass[i].gender == man)
				printf(" ║ Гендер бойца: мужчина             ║\n");
			if(fighter_mass[i].gender == woman)
				printf(" ║ Гендер бойца: женщина             ║\n");
	
				printf(" ║ Имя бойца: %s                ║\n", fighter_mass[i].name);
				printf(" ║ Количество единиц жизни бойца: %d  ║\n", fighter_mass[i].health);
				printf(" ║ Количество единиц урона бойца: %d  ║\n", fighter_mass[i].power );

			if(fighter_mass[i].bonus == none)
				printf(" ║ Бонус: нет                        ║\n");
			if(fighter_mass[i].bonus == shield_10)
				printf(" ║ Бонус: защита 10                  ║\n");
			if(fighter_mass[i].bonus == shield_20)
				printf(" ║ Бонус: защита 20                  ║\n");
			if(fighter_mass[i].bonus == extra_life)
				printf(" ║ Бонус: дополнительная жизнь       ║\n");
       
			if(fighter_mass[i].clancolor == green)
				printf(" ║ Клан бойца: зеленый               ║\n");
			if(fighter_mass[i].clancolor == red)
				printf(" ║ Клан бойца: красный               ║\n");
			if(fighter_mass[i].clancolor == blue)
				printf(" ║ Клан бойца: синий                 ║\n");	
				printf(" ╚═══════════════════════════════════╝ \n\n");
		}
	}
	else if( criterion == 2 )
	{	
		int struct_to_delete;
		printf(" ╔════════════════════════════════╗\n ║ Какую структуру удалять? (1-%d) ║ \n ╚════════════════════════════════╝\n ", N);
    		printf("  Введите критерий: ");
    		scanf("%d", &struct_to_delete);
		printf("\n");
		
		delete_struct((fighter *)fighter_mass, N, struct_to_delete);
	
		for( int i = 0; i < N - 1; i++)
		{
				printf(" ╔═══════════════════════════════════╗ \n");	
			if(fighter_mass[i].human == yes)
				printf(" ║ Боец - человек: да                ║ \n");
			if(fighter_mass[i].human == no)
				printf(" ║ Боец - человек: нет               ║\n");
			if(fighter_mass[i].gender == man)
				printf(" ║ Гендер бойца: мужчина             ║\n");
			if(fighter_mass[i].gender == woman)
				printf(" ║ Гендер бойца: женщина             ║\n");
				printf(" ║ Имя бойца: %s                ║\n", fighter_mass[i].name);
  				printf(" ║ Количество единиц жизни бойца: %d  ║ \n", fighter_mass[i].health);
				printf(" ║ Количество единиц урона бойца: %d  ║ \n", fighter_mass[i].power );
			if(fighter_mass[i].bonus == none)
				printf(" ║ Бонус: нет                        ║\n");
			if(fighter_mass[i].bonus == shield_10)
				printf(" ║ Бонус: защита 10                  ║\n");
			if(fighter_mass[i].bonus == shield_20)
				printf(" ║ Бонус: защита 20                  ║\n");
			if(fighter_mass[i].bonus == extra_life)
				printf(" ║ Бонус: дополнительная жизнь       ║\n");
			if(fighter_mass[i].clancolor == green)
				printf(" ║ Клан бойца: зеленый               ║\n");
			if(fighter_mass[i].clancolor == red)
				printf(" ║ Клан бойца: красный               ║\n");
			if(fighter_mass[i].clancolor == blue)
				printf(" ║ Клан бойца: синий                 ║\n");
				printf(" ╚═══════════════════════════════════╝ \n\n");
		}
	}

	clock_t endtime = clock();
	double time_spent = (double)(endtime - begin) / CLOCKS_PER_SEC;

	printf("\n\n Програма продлилась: %f сек.\n", time_spent);
	return 0;	
}									

