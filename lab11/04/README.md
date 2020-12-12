# Загальне завдання

1. **Розробити** 
Дано масив масивів з N * N цілих чисел. Елементи головної діагоналі записати в одновимірний масив, отриманий масив упорядкувати за зростанням.

## Опис програми

## Функціональне призначення
**Функціональне призначення**
Програма призначена для виписування елементів з головної діагоналі матриці N * N, та сортування "бульбашкою" цих елементів.

## Опис структури
**Опис структури**
	Програма складається з п*яти фунцій. Перша функція заовнює масив випадковими числами. Друга функція відділяє лінію для більш зручного прегляду. Третя фунція передає елементи головної діагоналі в інший масив. Роздільна лінія. Четверта функція робить сортування "Бульбашкою". П*ята функція виводить результат.
[Рисунок 1 - Блок схема] 
(https://drive.google.com/file/d/1ezdDQ_7hQeG9s7LWTGqTVeoH2epDFh4s/view?usp=sharing)
				  
# Реалізація програми на мові С
‘‘‘ #include <malloc.h>
#include <time.h>

void Filling(int** Mass, int N) {

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

void TransferingDiagonalElements(int* ResultMass, int** Mass, int N) {

    for (int i = 0; i < N; i++) {
        *(ResultMass + i) = *(*(Mass + i) + i);
        printf("%4d", *(ResultMass + i));
    }
}

void BubbleSort(int *ResultMass, int N) {

    int tmp;


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

void Output(int *ResultMass, int N) {

    for (int i = 0; i < N; i++) {
        printf("%4d", *(ResultMass + i));
    }
}

int main()
{
    srand(time(NULL));
 
    int N = rand() % 10;

    int* ResultMass = (int*)malloc(N * sizeof(int));

    int** Mass = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        *(Mass + i) = (int*)malloc(N * sizeof(int));
    }

    Filling((int**)Mass, N);

    DividingLine(N);

    TransferingDiagonalElements((int*)ResultMass, (int**)Mass, N);

    DividingLine(N);
   
    BubbleSort((int*)ResultMass, N);
    
    Output((int*)ResultMass, N);
    
    return 0;
} ‘‘‘
## Результат роботи програми
Результат роботи програми на (Рис. 2) 
[Рисунок 2 - nemiver]
(https://prnt.sc/vweqyj)


@author Steghniy B.
@date 12-dec-2020


