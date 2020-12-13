# Загальне завдання

1. **Розробити** 
Текст - це програма на мові С. Визначити, скільки в ньому операторів циклу.

## Опис програми

## Функціональне призначення
**Функціональне призначення**
Програма призначена для визначення кількості операторів циклу в коді.
				  
# Реалізація програми на мові С
‘‘‘
int main()
{
  char str[] = "int main() \n { int a = 16; \n int b = 4; \n int result = 0; \n for (int nod = a; nod > 0; nod--){ if (a % nod == 0 && b % nod == 0) \n { \n result = nod; \n break; \n } \n } \n int nod = a; \n while (nod > 0) \n { \n if (a % nod == 0 && b % nod == 0) \n { \n result = nod; \n break; \n } \n nod--; \n } \n return 0; \n }";
  printf("%s\n", str);
  int Count = 0;
  
  char* strSpaces = strtok(str, " ");
  
  char FindFor[] = "for";
  char FindWhile[] = "while";
  char FindDo[] = "do";
  for (int i = 0; strSpaces != NULL; i++)
  {
    if ((strcmp(strSpaces, FindFor) == 0) || (strcmp(strSpaces, FindWhile) == 0) || (strcmp(strSpaces, FindDo) == 0)) {
      Count++;
    }
    strSpaces = strtok(NULL, " "); 
  }
    
    printf("Number of cycles: %d ", Count);
  
  return 0;
} 
‘‘‘


@author Steghniy B.
@date 13-dec-2020


