/**
*@mainpage
*# Загальне завдання
*1. **Завдання**
*	Текст - це програма на мові С. Визначити, скільки в ньому операторів циклу.
*
*# Опис програми
*2. **Призачення**
*	Програма призначена для визначення кількості операторів циклу в коді.
*@author Steghniy B.
*@date 13-dec-2020
*/

/**
* @file main.c
* Програма призначена для визначення кількості операторів циклу в коді.
*@author Steghniy B.
*@return 0
*@version 0.1 
*@date 13-dec-2020
*/
#include <stdio.h>
#include <string.h>

int main()
{
  /** Строка з кодом */
  char str[] = "int main() \n { int a = 16; \n int b = 4; \n int result = 0; \n for (int nod = a; nod > 0; nod--){ if (a % nod == 0 && b % nod == 0) \n { \n result = nod; \n break; \n } \n } \n int nod = a; \n while (nod > 0) \n { \n if (a % nod == 0 && b % nod == 0) \n { \n result = nod; \n break; \n } \n nod--; \n } \n return 0; \n }";
  printf("%s\n", str);
  /** Змінна, яка відповідає за кількість циклів у коді */
  int Count = 0;
  
  /** Розділяє слово від пробілу до пробілу */
  char* strSpaces = strtok(str, " ");
  
  char FindFor[] = "for";
  char FindWhile[] = "while";
  char FindDo[] = "do";
  for (int i = 0; strSpaces != NULL; i++)
  {
    /** Порівнює дві строки між собою */
    if ((strcmp(strSpaces, FindFor) == 0) || (strcmp(strSpaces, FindWhile) == 0) || (strcmp(strSpaces, FindDo) == 0)) {
      Count++;
    }
    strSpaces = strtok(NULL, " "); 
  }
    
    printf("Number of cycles: %d ", Count);
  
  return 0;
}
