/**
*@mainpage
*# Загальне завдання
*1. **Завдання**
*	Видати на екран розмір запитуваного файлу та його атрибути
*
*# Опис програми
*2. **Призачення**
*	Програма призначеня для визначення розміру файлу, а також для видачі його атрибутів
*3. **Логічна структура**
*	Програма складається з однієї функції
*@author Steghniy B.
*@date 22-feb-2021
*/

/**
* @file main.c
* ППрограма призначеня для визначення розміру файлу, а також для видачі його атрибутів
*@author Steghniy B.
*@return 0
*@version 0.1
*@date 22-feb-2021
*/


#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

 int main()
 {
 	struct stat statbuf;
  
 	/* Задаем название файла, в который будет записыватся результат */
 	char resultfilename[50];
 	printf("Введите название результируещего файла: ");
 	scanf("%s", &resultfilename);
 	
	/* Открытие файла */
	FILE *file = fopen("/home/mioyos/test/test.txt", "r");
	FILE *file2 = fopen(resultfilename, "w");
	/* Проверка файла на открытие */
	if (file != NULL){
		printf("Файл успешно открыт!\n");
		} else {
		printf("Файл не был открыт. Попробуйте ввести правильный путь к файлу.\n");
		exit(1);
	}
	if (file2 != NULL){
		printf("Файл для записи результата был успешно создан!\n");
		} else {
		printf("Файл для записи результата не был создан\n");
		exit(1);
	}
	
	/* Устанавливаем позицию в файле(в конец) */
	fseek(file, 0, SEEK_END);
	
	/* Переменная count равняется текущей позиции в файле, которую мы установили ранее */
	int count = ftell(file);
	
	/* Вывод результата в консоль и в файл */
	printf("Размер файла: %d байт.\n",  count);
	fprintf(file2, "Размер файла: %d байт.\n", count);
	
	/* Получаем информацию о файле */
	fflush(file);
	
	/* Записываем информацию об открытом файле в стркутуру stat */
	fstat(fileno(file),&statbuf); 
	
	/* Вывод атрибутов в консоль и в файл*/
   	if(statbuf.st_mode & S_IREAD){
     	printf("Присутствует разрешение на чтение\n");
	}
	
   	if(statbuf.st_mode & S_IWRITE){
	printf("Присутствует разрешение на запись\n");
	}
	
	printf("Файл расположен на диске: %c\n",'A' + statbuf.st_dev);
	printf("Время последнего открытия: %s", ctime(&statbuf.st_ctime) );
	printf("Время последнего изменения: %s\n", ctime(&statbuf.st_mtime) );
	
	if(statbuf.st_mode & S_IREAD){
     	fprintf(file2,"Присутствует азрешение на чтение\n");
	}
	
   	if(statbuf.st_mode & S_IWRITE){
	fprintf(file2,"Присутствует разрешение на запись\n");
	}
	
	fprintf(file2,"Файл расположен на диске: %c\n",'A' + statbuf.st_dev);
	fprintf(file2,"Время последнего открытия: %s", ctime(&statbuf.st_ctime) );
	fprintf(file2,"Время последнего изменения: %s\n", ctime(&statbuf.st_mtime) );
	
	/* Закрытие файлов */
	fclose(file);
	fclose(file2);
	
	return 0;
}
