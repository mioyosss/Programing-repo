#include <stdio.h>
#include <string.h>

int main()
{
	FILE *matrix = fopen("/home/mioyos/Programing-repo/lab12,14/lab14/2/matrix","r");
	/* Запись размера масива. Преобразование char в int */
	int M = fgetc(matrix) - '0';
	fseek(matrix,2,SEEK_SET );
	int N = fgetc(matrix) - '0';

	/* Преобразование char в int */
	printf("Размер матрицы M на N: %d на %d\n", M, N);
	
	float mass[M][N];
	/* Перепрыгиваем через пробелы в файле */
	fseek(matrix,1,SEEK_CUR );
	printf("Ваша матрица: \n");
	/* Заполнения матрицы с файла */
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
		mass[i][j] = fgetc(matrix) - '0';
		fseek(matrix,1,SEEK_CUR);
		printf("%.0f\t", mass[i][j]);
		}
	printf("\n");
	}
	
	/* Проверка матрицы */
	if(M != N){
		printf("Матрица не квадратная (%d не равно %d). Вычисление детермината невозможно.\n",M, N);
	} else if (M == N) {
	printf("Матрица квадратная (%d = %d)\n",M, N);
	float tmp, det;
	/* Поиск детермината матрицы */
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
            		if(j>i){
                	tmp = mass[j][i]/mass[i][i];
                	for(int k = 0; k < N; k++){
                    	mass[j][k] -= tmp * mass[i][k];
                	}
            	}
       }
}
    	det = 1;
    	for(int i = 0; i < N; i++){
        	det *= mass[i][i];
       	}
       	
	printf("Детерминат матрицы: %.0f\n", det);
}
	return 0;
}
