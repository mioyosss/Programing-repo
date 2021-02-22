#include <stdio.h>
#include <string.h>
#define LEN 1000

 int main()
 {
 /** Задаємо назву файлу */
 char newtxt[20];
 printf("Введите название файла: ");
 scanf("%s", &newtxt);
 /* Змінна для зчитування з файлу */
 char str[LEN];

 /** Змінна, яка відповідає за кількість циклів у коді */
 int Count = 0;
 
 /* Відкриття файлу */
 FILE *file;
 file = fopen(newtxt, "w"); 
 /* Перевірка на створення файлу */
 if (file != NULL){
 printf("Файл успешно создан!\n");
 } else {
 printf("Файл не был создан\n");
 exit(1);
 }
  
 /* Запис коду до файлу */
 fprintf(file, " int main() \n { int a = 16; \n int b = 4; \n int result = 0; \n for() { if (a nod == 0 && b nod == 0) \n { \n result = nod; \n break; \n } \n } \n int nod = a; \n while() \n { \n if (a nod == 0 && b nod == 0) \n { \n result = nod; \n break; \n } \n nod--; \n } \n return 0; \n } \n ");

 fclose(file);

 file = fopen(newtxt, "r");
 /* Построчний запис до строки з файлу */
 while(fgets(str, LEN, file))
 {

 fprintf(stdout, "%s", str);

 /** Розділяє слово від пробілу до пробілу */
 char* strSpaces = strtok(str, " ");
  
 char FindFor[] = "for()";
 char FindWhile[] = "while()";
  
 for (int i = 0; strSpaces != NULL; i++)
 {
 /** Порівнює дві строки між собою */
 if ((strcmp(strSpaces, FindFor) == 0) || (strcmp(strSpaces, FindWhile) == 0)) {
 Count++;
 }
 strSpaces = strtok(NULL, " "); 
 }
 }
 fclose(file);

 printf("Number of cycles: %d ", Count);
	
 file = fopen(newtxt, "a"); 	
 fprintf(file, "Number of cycles: %d ", Count);	
 fclose(file);

  return 0;
}
