#include <stdlib.h>
#include <time.h>

// Задаємо розмір матриці константою
#define N 3 

void zap(int mat[N][N]){
	srand (time(NULL));
	for (int i = 0; i < N; i++){
	for (int j = 0; j < N; j++){
	mat[i][j] = rand() % 10;
	}
	}
}

// Задаємо функію, яка буде рахувати множення матриці саму на себе
void func(int mat[N][N], int matmat[N][N]) {

    //Основний алгоритм знайдення добутку матриць
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int p = 0; p < N; p++) {
                matmat[i][j] += mat[i][p] * mat[p][j];
            }
        }
    }

}

int main()
{
    // Задаємо массив, який буде виповнювати роль матриці
    int mat[N][N];
    zap(mat);
    // Задаємо матрицю для результату
    int matmat[N][N] = {};
    // Виклик функції
    func(mat, matmat);

    return 0;
}
