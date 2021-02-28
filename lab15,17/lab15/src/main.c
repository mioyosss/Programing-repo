#include "lib.h"

/**
*@mainpage
*# Загальне завдання
*1. **Завдання**
*	З розділу "Розрахункове завдання" взяти галузь за номером свого варіанту та зробити завдання.
*
*# Опис програми
*2. *Опис*
* 	Програма складається з девяти функцій та структури
*@author Steghniy B.
*@date 13-dec-2020
*/

/**
* @file main.c
* @author Steghniy B.
* @return 0
* @version 0.1 
* @date 13-dec-2020
*/

#define N 3
int main()
{
	FILE *read = fopen("/home/mioyos/Programing-repo/lab15,17/lab15/FIGHTERS.txt", "r");
	FILE *write = fopen("result","w");
	FILE *search = fopen("/home/mioyos/Programing-repo/lab15,17/lab15/searchfighter.txt", "r");

	if (read != NULL){
		printf("Файл для чтения успешно открыт!\n\n");
		} else {
		printf("Файл для чтения не был открыт. Попробуйте ввести правильный путь к файлу.\n\n");
		exit(1);	
	}
	
	if (write != NULL){
		printf("Файл для записи успешно создан!\n\n");
		} else {
		printf("Файл для записи не был создан\n\n");
		exit(1);	
	}
	
	if (search != NULL){
		printf("Файл для чтения успешно открыт!\n\n");
		} else {
		printf("Файл для чтения не был открыт. Попробуйте ввести правильный путь к файлу.\n\n");
		exit(1);	
	}
		
						/* Задание 4.1 */	printf("______________________________________________\n\n\n");						
	fighter fighter_mass[N];
						
	read_from_file( read, fighter_mass, N);
	
	outputfunc(fighter_mass, N);
	
	write_to_file(write, fighter_mass, N);

						/* Задание 4.2 */
	printf("______________________________________________\n\n\n");	
	sort(fighter_mass, N);
	
						/* Задание 4.3 */
	printf("______________________________________________\n\n\n");			
	fighter mass[N];
	read_from_file( search, mass, N);
	printf("%d\n", searchclan(mass, N));
	
	
						/* Задание 4.4 */
	printf("______________________________________________\n\n\n");	
	randfunc(fighter_mass, N);
	
						/* Задание 5 */
	printf("______________________________________________\n\n\n");
				
	FILE *binwrite = fopen("binarytask.dat", "wb");
	for ( int i = 0; i < N; i++ )
		write_to_binfile( binwrite, fighter_mass, i );
	
	fclose(binwrite);

	FILE *binread = fopen("binarytask.dat", "rb");
	for ( int i = 0; i < N; i++ )
		read_from_binfile ( binread, fighter_mass, i );

	fclose(binread);

	outputfunc( fighter_mass, N );
	
	fclose(read);
	fclose(write);
	fclose(search);
										
	return 0;
}
