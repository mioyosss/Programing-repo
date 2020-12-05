#include <stdlib.h>
#include <time.h>

// Розмір матриці константою
#define N 5

void zap(int mat[][N]){
	srand (time(NULL));
	for (int i = 0; i < N; i++){
	for (int j = 0; j < N; j++){
	mat[i][j] = rand() % 100;
	}
	}
}


int func(int mat[N][N]) {
    // Буферна змінна
    int tmp = 0; 
    // Цикл для перестановки елементів матриці та їх зсуву 
    for (int i = 0; i < N; i++) { 
        tmp = mat[i][0];
        for (int j = 0; j < N; j++) {
            mat[i][j] = mat[i][j + 1];
        }
        mat[i][N - 1] = tmp;

    }
    return 0;
}

int main()
{
    // Задаємо матрицю, розмір якої N * N
    
    int mat[N][N];
    
    zap(mat);
    // Виклик фунції для циклічного зсуву матриці вліво
    func(mat);

    return 0;
}
