/**
*@mainpage
*# Загальне завдання
*1. **Завдання**
*	Дано масив масивів з N * N цілих чисел. Елементи головної діагоналі записати в одновимірний масив, *отриманий масив упорядкувати за зростанням. Також потрібно використовувати функції для введеня і виведення даних.
*
*# Опис програми
*2. **Призачення**
*	Програма призначена для виписування елементів з головної діагоналі матриці N * N, та сортування *"бульбашкою" цих елементів.
*3. **Логічна структура**
*	Програма складається з п*яти фунцій. Перша функція заовнює масив *випадковими числами. Друга функція   *відділяє лінію для більш зручного прегляду. Третя фунція передає елементи головної діагоналі в інший масив. *Роздільна лінія. Четверта функція робить сортування "Бульбашкою". П*ята функція виводить результат.
*@author Steghniy B.
*@date 12-feb-2021
*/

/**
* @file main.c
* Програма призначена для виписування елементів з головної діагоналі матриці N * N, та сортування "бульбашкою" цих елементів.
*@author Steghniy B.
*@return 0
*@version 0.2
*@date 12-feb-2021
*/

#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <time.h>

/** @Filling Функція для заповнення масиву випадковими числами */
void Filling(int** Mass, int N) {
    /* Змінна "лічильник" */
    int z = 0;
    // Цикл для заповнення 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Введите %d элемент массива: ", z+1);
            scanf("%d", &Mass[i][j]);
            z++;
        }
        printf("\n");
    }
    
    printf("Ваш массив: \n");
     /* Цикл для виведення массиву */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", *(*(Mass + i) + j));
        }
        printf("\n");
    }

}

/** @TransferingDiagonalElements Функція для передачі діагональних елементів в масив для результату*/
void TransferingDiagonalElements(int* ResultMass, int** Mass, int N) {
    printf("\n");
    printf("Диагональные элементы: ");
    /* Цикл для перенесення діагональних елементів в массив для результату */
    for (int i = 0; i < N; i++) {
        *(ResultMass + i) = *(*(Mass + i) + i);
        printf("%d\t", *(ResultMass + i));
    }
    printf("\n\n");
}

/** @BubbleSort Функція для сортування масиву "бульбашкою"*/
void BubbleSort(int* ResultMass, int N) {
    /* Буферна змінна для перестановки елементів масиву */
    int tmp;
    /* Цикл для "сортування бульбашкою" результуючого масиву */
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (*(ResultMass + j) > *(ResultMass + j + 1)) {
                tmp = *(ResultMass + j);
                *(ResultMass + j) = *(ResultMass + j + 1);
                *(ResultMass + j + 1) = tmp;
            }
        }
    }

}

/** @Output Функція для виведення результуючого масиву*/
void Output(int* ResultMass, int N) {
    printf("Сортировка диагональных элементов: ");
    /* Цикл для виведення елементів масиву */
    for (int i = 0; i < N; i++) {
        printf("%d\t", *(ResultMass + i));
    }
    printf("\n\n");
}

/** Основна фунція @main */
int main()
{
    /* Створюємо змінні, які знадобляться у подальших процесах введення та виведення */
    char initial; 
    char group[4];
    char name[100];
    char theme[200];
    
    /* Збір та виведення інформації про користувача */
    printf("Введите номер и тему лаборатрной работы: ");
    gets(theme);
    printf("Номер и тема лаборатрной работы: ");
    puts(theme);
    
    printf("Введите вашу группу: ");
    gets(group);
    printf("Ваша группа: ");
    puts(group);
    
    printf("Введите ваше имя: ");
    gets(name);
    printf("Ваше имя: ");
    puts(name);
    
    printf("Введите первую букву своего имени: ");
    initial = getc (stdin);
    printf("Первая буква вашего имени: ");
    putc (initial, stdout);
    printf("\n");

    /* Визначення розміру масиву */
    int N;
    printf("Введите размер массива: ");
    scanf("%d", &N);
    for (int i = 0; N < 1; i++) {
        if (N < 1) {
            printf("Введите положительное число (больше нуля): ");
            scanf("%d", &N);
        }
    }
    printf("\n");

    /* Задання динамічного масиву для запису туди результату */
    int* ResultMass = (int*)malloc(N * sizeof(int));
    
    /* Задання динамічного двовимірного масиву */
    int** Mass = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        *(Mass + i) = (int*)malloc(N * sizeof(int));
    }
    
    /** Звернення до фунції @Filling */
    Filling((int**)Mass, N);

    /** Звернення до фунції @TransferingDiagonalElements */
    TransferingDiagonalElements((int*)ResultMass, (int**)Mass, N);

    /** Звернення до фунції @BubbleSort */
    BubbleSort((int*)ResultMass, N);

    /** Звернення до фунції @Output */
    Output((int*)ResultMass, N);

    return 0;
}
