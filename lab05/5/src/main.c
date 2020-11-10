#include <stdio.h>
int main()
{
	// Вводимо змінну а та задаємо її значення
	int a = -5;
	// Вводимо змінну koren та задаємо її значення (корінь змінної числа а)
	int koren = 0;
	
	
	// Додаємо оператор циклу for, змінну i, умову та приріст
	for(int i = 0; i <= a; i++){
	if(a == i * i){
	koren = i;
	break;
	}
	}
	
	
	
	int i = 0;
	// Додаємо оператор циклу while..do 
	while (i <= a){
	if(a == i * i){
	koren = i;
	break;
	}
	i++;
	}
	
	
	int i = 0;
	// Додаємо оператор циклу do..while
	do{
	if(a == i * i){
	koren = i;
	break;
	}
	i++;
	}
	while (i <= a);
	
	
	// Конструкція if..else для позначення результату
	if (a < 0){
	printf(" Корня не будет ");
	}else{
	printf("Корень:%d", koren );
	}
	
	
	
	return 0;
}
