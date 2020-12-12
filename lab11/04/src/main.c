/**
*@mainpage
*# Загальне завдання
*1. **Завдання**
*	Дано масив масивів з N * N цілих чисел. Елементи головної діагоналі *записати в одновимірний масив, отриманий масив упорядкувати за зростанням.
*
*# Опис програми
*2. **Призачення**
*	Програма призначена для виписування елементів з головної діагоналі матриці *N * N, та сортування "бульбашкою" цих елементів.
*3. **Логічна структура**
*	Програма складається з п*яти фунцій. Перша функція заовнює масив *випадковими числами. Друга функція відділяє лінію для більш зручного прегляду. *Третя фунція передає елементи головної діагоналі в інший масив. Роздільна лінія. *Четверта функція робить сортування "Бульбашкою". П*ята функція виводить результат.
*@author Steghniy B.
*@date 12-dec-2020
*/

/**
* @file main.c
* Програма призначена для виписування елементів з головної діагоналі матриці *N * *N, та сортування "бульбашкою" цих елементів.
*@author Steghniy B.
*@return 0
*@version 0.1 
*@date 12-dec-2020
*/
#include <malloc.h>
#include <time.h>
/** @Filling Функція для заповнення масиву випадковими числами */
void Filling(int** Mass, int N) {
    /* Цикл для заповнення масиву випадковими числами */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(Mass + i) + j) = rand() % 10;
            printf("%4d", *(*(Mass + i) + j));
        }
        printf("\n");
    }
}
/** @DividingLine Функція для заповнення відділення масивів*/
void DividingLine(int N) {
    for (int i = 0; i < N * 4; i++) {
        printf("_");
    }
    printf("\n");
}
/** @TransferingDiagonalElements Функція для передачі діагональних елементів в масив для результату*/
void TransferingDiagonalElements(int* ResultMass, int** Mass, int N) {
    /* Цикл для перенесення діагональних елементів в массив для результату */
    for (int i = 0; i < N; i++) {
        *(ResultMass + i) = *(*(Mass + i) + i);
        printf("%4d", *(ResultMass + i));
    }
}
/** @BubbleSort Функція для сортування масиву "бульбашкою"*/
void BubbleSort(int *ResultMass, int N) {
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
void Output(int *ResultMass, int N) {
    /* Цикл для виведення елементів масиву */
    for (int i = 0; i < N; i++) {
        printf("%4d", *(ResultMass + i));
    }
}
/** Основна фунція @main */
int main()
{
    srand(time(NULL));
    /* Визначення розміру масиву */
    int N = rand() % 10;
    /* Задання динамічного масиву для запису туди результату */
    int* ResultMass = (int*)malloc(N * sizeof(int));
    /* Задання динамічного двовимірного масиву */
    int** Mass = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        *(Mass + i) = (int*)malloc(N * sizeof(int));
    }
     /** Звернення до фунції @Filling */
    Filling((int**)Mass, N);
     /** Звернення до фунції @DividingLine */
    DividingLine(N);
     /** Звернення до фунції @TransferingDiagonalElements */
    TransferingDiagonalElements((int*)ResultMass, (int**)Mass, N);
     /** Звернення до фунції @DividingLine */
    DividingLine(N);
        /** Звернення до фунції @BubbleSort */
    BubbleSort((int*)ResultMass, N);
         /** Звернення до фунції @Output */
    Output((int*)ResultMass, N);
    
    return 0;
}
