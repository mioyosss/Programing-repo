#include <malloc.h>
#include <time.h>

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

void DividingLine(int N) {
    for (int i = 0; i < N * 4; i++) {
        printf("_");
    }
    printf("\n");
}

void FindMax(int* ResultMass,int** Mass, int N) {
    /* Цикл для знайдення максмального значення елементу серед стовпця */
    for (int i = 0; i < N; i++) {
        /* Змінна, яка записує максимальне значення елементу стовпця */
        int MaxValue = *(*(Mass + 0) + i);
        for (int j = 1; j < N; j++) {
            if (*(*(Mass + j) + i) > MaxValue)
                MaxValue = *(*(Mass + j) + i);
        }
        /* Запис максимальних чисел у масив */
        *(ResultMass + i) = MaxValue;
        printf("%4d", *(ResultMass + i));
    }
}

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

    Filling((int**)Mass, N);

    DividingLine(N);

    FindMax((int*)ResultMass,(int**)Mass, N);

    return 0;
}
