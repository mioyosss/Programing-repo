#include "lib.h"

/**
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Steghniy B.
 * @date 27-jan-2021
 * @version 0.1
 */

						/* Задание 4.1 */

read_from_file(FILE *read, fighter *fighter_mass, int n){

	for(int i = 0; i < n; i++){
	
	char human[20];
	char gender[20];
	char name[20];
	char bonus[20];
	char clancolor[20];
	
	fscanf(read,"%s", human );
	
	 if ( strcmp(human, "yes") == 0 )
            fighter_mass[i].human = 0;

        if ( strcmp(human, "no") == 0 )
            fighter_mass[i].human = 1;
	
	fscanf(read,"%s", gender );

        if ( strcmp(gender, "man") == 0 )
            fighter_mass[i].gender = 0;

        if ( strcmp(gender, "woman") == 0 )
            fighter_mass[i].gender = 1;

	fscanf(read,"%s", &fighter_mass[i].name );
	
	fscanf(read,"%d", &fighter_mass[i].health);
	
	fscanf(read,"%d", &fighter_mass[i].power);
	
	fscanf(read,"%s", bonus );

        if ( strcmp(bonus, "none") == 0 )
            fighter_mass[i].bonus = 0;

        if ( strcmp(bonus, "shield_10") == 0 )
            fighter_mass[i].bonus = 1;
            
        if ( strcmp(bonus, "shield_20") == 0 )
            fighter_mass[i].bonus = 2;
	
	if ( strcmp(bonus, "extra_life") == 0 )
            fighter_mass[i].bonus = 3;
	
	fscanf(read,"%s", clancolor );
	
	 if ( strcmp(clancolor, "green") == 0 )
            fighter_mass[i].clancolor = 0;
	
	 if ( strcmp(clancolor, "red") == 0 )
            fighter_mass[i].clancolor = 1;
            
         if ( strcmp(clancolor, "blue") == 0 )
            fighter_mass[i].clancolor = 2;
	}
}



void outputfunc(fighter *fighter_mass, int n )
{   
    for ( int i = 0; i < n; i++)
    {
	if(fighter_mass[i].human == yes)
	printf("Боец - человек: да\n");
	if(fighter_mass[i].human == no)
	printf("Боец - человек: нет\n");
	
	if(fighter_mass[i].gender == man)
	printf("Гендер бойца: мужчина\n");
	if(fighter_mass[i].gender == woman)
	printf("Гендер бойца: женщина\n");
	
	printf("Имя бойца: %s\n", fighter_mass[i].name);

        printf("Количество единиц жизни бойца: %d\n", fighter_mass[i].health);
        printf("Количество единиц урона бойца: %d\n", fighter_mass[i].power );

	if(fighter_mass[i].bonus == none)
	printf("Бонус: нет\n");
	if(fighter_mass[i].bonus == shield_10)
	printf("Бонус: защита 10\n");
	if(fighter_mass[i].bonus == shield_20)
	printf("Бонус: защита 20\n");
	if(fighter_mass[i].bonus == extra_life)
	printf("Бонус: дополнительная жизнь\n");
       
	if(fighter_mass[i].clancolor == green)
	printf("Клан бойца: зеленый\n");
	if(fighter_mass[i].clancolor == red)
	printf("Клан бойца: красный\n");
	if(fighter_mass[i].clancolor == blue)
	printf("Клан бойца: синий\n");

	printf("\n\n");
    }
}



int write_to_file(FILE *write, fighter *fighter_mass, int n){
	for(int i = 0; i < n; i++){
	fprintf(write, "Боец - человек: %s\nБоец мужчина или женщина: %s\nИмя бойца: %s\nКоличество очков жизни бойца: %d\nКоличество очков силы бойца: %d\n",fighter_mass[i].human == yes ? "да":"нет", fighter_mass[i].gender == man ? "мужчина":"женщина", fighter_mass[i].name, fighter_mass[i].health, fighter_mass[i].power);
	
	if(fighter_mass[i].bonus == none)
	fprintf(write,"Бонус: нет\n");
	if(fighter_mass[i].bonus == shield_10)
	fprintf(write,"Бонус: защита 10\n");
	if(fighter_mass[i].bonus == shield_20)
	fprintf(write,"Бонус: защита 20\n");
	if(fighter_mass[i].bonus == extra_life)
	fprintf(write,"Бонус: дополнительная жизнь\n");
	
	if(fighter_mass[i].clancolor == green)
	fprintf(write,"Клан бойца: зеленый\n\n");
	if(fighter_mass[i].clancolor == red)
	fprintf(write,"Клан бойца: красный\n\n");
	if(fighter_mass[i].clancolor == blue)
	fprintf(write,"Клан бойца: синий\n\n");
	}
}

						/* Задание 4.2 */

int sort(fighter *fighter_mass, int n){
	int sorttype = 0;
	printf("1. Является ли боец человеком (сортировка по алфавиту) \n");
	printf("2. Пол бойца (сортировка по алфавиту)\n");
	printf("3. Имя бойца (сортировка по алфавиту)\n");
	printf("4. Количество едини жизни бойца (сортировка по возростанию)\n");
	printf("5. Количество единиц наносимого урона бойца (сортировка по возростанию)\n");
	printf("6. Усиление бойца (сортировка по алфавиту)\n");	
	printf("7. Клан бойца (сортировка по алфавиту)\n\n");
	
	printf("Выберите критерий, по которому будет производится сортировка: ");
	scanf("%d", &sorttype);
	printf("\n");
	
	switch(sorttype){
	case 1:
		sort_enum(fighter_mass, n, sorttype);
		break;
	case 2:
		sort_enum(fighter_mass, n, sorttype);
		break;
	case 3:
		sort_alphabet(fighter_mass, n, sorttype);
		break;
	case 4:
		sort_ascending(fighter_mass, n, sorttype);
		break;
	case 5:
		sort_ascending(fighter_mass, n, sorttype);
		break;	
	case 6:
		sort_enum(fighter_mass, n, sorttype);
		break;	
	case 7:	
		sort_enum(fighter_mass, n, sorttype);
		break;	
	}	
}



int sort_enum(fighter *fighter_mass, int n, int sorttype){
	int tmp = 0;
	if(sorttype == 1){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			if(fighter_mass[j].human > fighter_mass[j+1].human){
			tmp = fighter_mass[j+1].human;
			fighter_mass[j+1].human = fighter_mass[j].human;
			fighter_mass[j].human = tmp;
			} 
		}
	}
	for (int i = 0; i < n; i++){
		if(fighter_mass[i].human == 0)
		printf("Боец - человек: да\n");
		if(fighter_mass[i].human == 1)
		printf("Боец - человек: нет\n");
		}
	}
	if(sorttype == 2){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			if(fighter_mass[j].gender > fighter_mass[j+1].gender){
			tmp = fighter_mass[j+1].gender;
			fighter_mass[j+1].gender = fighter_mass[j].gender;
			fighter_mass[j].gender = tmp;
			} 
		}
	}
	for (int i = 0; i < n; i++){
		if(fighter_mass[i].gender == 0)
		printf("Гендер бойца: мужчина\n");
		if(fighter_mass[i].gender == 1)
		printf("Гендер бойца: женщина\n");
		}
	}
	if(sorttype == 6){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			if(fighter_mass[j].bonus > fighter_mass[j+1].bonus){
			tmp = fighter_mass[j+1].bonus;
			fighter_mass[j+1].bonus = fighter_mass[j].bonus;
			fighter_mass[j].bonus = tmp;
			} 
		}
	}
	for (int i = 0; i < n; i++){
		if(fighter_mass[i].bonus == 0)
		printf("Бонус: нет\n");
		if(fighter_mass[i].bonus == 1)
		printf("Бонус: защита 10\n");
		if(fighter_mass[i].bonus == 2)
		printf("Бонус: защита 20\n");
		if(fighter_mass[i].bonus == 3)
		printf("Бонус: дополнительная жизнь\n");
		}
	}
	if(sorttype == 7){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			if(fighter_mass[j].clancolor > fighter_mass[j+1].clancolor){
			tmp = fighter_mass[j+1].clancolor;
			fighter_mass[j+1].clancolor = fighter_mass[j].clancolor;
			fighter_mass[j].clancolor = tmp;
			} 
		}
	}
	for (int i = 0; i < n; i++){
		if(fighter_mass[i].clancolor == 0)
		printf("Клан бойца: зеленый\n");
		if(fighter_mass[i].clancolor == 1)
		printf("Клан бойца: красный\n");
		if(fighter_mass[i].clancolor == 2)
		printf("Клан бойца: синий\n");
		}
	}
	printf("\n");
}



int sort_alphabet(fighter *fighter_mass, int n, int sorttype){
	char tmp[100];
	if (sorttype == 3){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
		if ( strcmp( fighter_mass[j].name, fighter_mass[j+1].name) >= 0 ) {    
			strcpy(tmp, fighter_mass[j+1].name );
			strcpy(fighter_mass[j+1].name, fighter_mass[j].name);
			strcpy(fighter_mass[j].name, tmp );
		        }
		}           
	}
	for (int i = 0; i < n; i++){
		printf("Имя бойца: %s\n", fighter_mass[i].name ); 
			
	}
}
printf("\n");
}



int sort_ascending(fighter *fighter_mass, int n, int sorttype){
	int tmp;
	if ( sorttype == 4 ){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n-1; j++){		
			if (fighter_mass[j].health > fighter_mass[j+1].health){    
			tmp = fighter_mass[j+1].health;
			fighter_mass[j+1].health = fighter_mass[j].health;
			fighter_mass[j].health = tmp;
			}
		}            
	}

        for (int i = 0; i < n; i++) 
            printf("Количество единиц жизни бойца: %d\n", fighter_mass[i].health ); 
    }
    
    if ( sorttype == 5 ){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n-1; j++){		
			if (fighter_mass[j].power > fighter_mass[j+1].power){    
			tmp = fighter_mass[j+1].power;
			fighter_mass[j+1].power = fighter_mass[j].power;
			fighter_mass[j].power = tmp;
			}
		}            
	}
	for (int i = 0; i < n; i++) 
	printf("Количество единиц наносимого урона бойца: %d\n", fighter_mass[i].power ); 
    }
    printf("\n");
}



						/* Задание 4.3 */


short int searchclan(fighter *mass, int n){
	int count_red = 0;
	int count_green = 0;
	int count_blue = 0;
	for(int i = 0; i < n; i++){
	if(mass[i].clancolor == red){
	count_red++;
	}
	}
	
	for(int i = 0; i < n; i++){
	if(mass[i].clancolor == green){
	count_green++;
	}
	}
	
	for(int i = 0; i < n; i++){
	if(mass[i].clancolor == blue){
	count_blue++;
	}
	}
	
	printf("Количество бойцов красного клана: %d\nКоличество бойцов зеленого клана: %d\nКоличество бойцов синего клана: %d\n",count_red,count_green,count_blue);
	printf("\n");
	
	if(count_red > count_blue && count_red > count_green)
		return count_red;
	else if(count_blue > count_red && count_blue > count_green)
		return count_blue;
	else if(count_green > count_red && count_green > count_blue)
		return count_green;
	else
		return 0;
}	


						/* Задание 4.4 */

void randfunc(fighter *fighter_mass, int n){
	srand(time(NULL));
	for(int i = 0; i < n; i++){
	
	fighter_mass[i].human = rand() % 2;
	
	fighter_mass[i].gender = rand() % 2;
	
	sprintf(fighter_mass[i].name, "Боец №%d", rand() % 210 + 21);
	
	fighter_mass[i].health = rand() % 210 + 21;
	
	fighter_mass[i].power = rand() % 210 + 21;
	
	fighter_mass[i].bonus = rand() % 4;
	
	fighter_mass[i].clancolor = rand() % 3;
	}
	
	for(int i = 0; i < n; i++){
		
	if(fighter_mass[i].human == yes)
	printf("Боец: человек\n");
	
	if(fighter_mass[i].human == no)
	printf("Боец: не человек\n");
	
	if(fighter_mass[i].gender == man)
	printf("Пол бойца: мужчина\n");
	
	if(fighter_mass[i].gender == woman)
	printf("Пол бойца: женщина\n");
	
	printf("Имя бойца: %s\n", fighter_mass[i].name);
	printf("Количество очков здоровья бойца: %d\n", fighter_mass[i].health);
	printf("Количество очков урона бойца: %d\n", fighter_mass[i].power);
	
	if(fighter_mass[i].bonus == none)
	printf("Бонус: нет\n");
	if(fighter_mass[i].bonus == shield_10)
	printf("Бонус: защита 10\n");
	if(fighter_mass[i].bonus == shield_20)
	printf("Бонус: защита 20\n");
	if(fighter_mass[i].bonus == extra_life)
	printf("Бонус: дополнительная жизнь\n");
       
	if(fighter_mass[i].clancolor == green)
	printf("Клан бойца: зеленый\n");
	if(fighter_mass[i].clancolor == red)
	printf("Клан бойца: красный\n");
	if(fighter_mass[i].clancolor == blue)
	printf("Клан бойца: синий\n");

	printf("\n\n");
	}
}

void write_to_binfile ( FILE *binwrite, fighter *fighter_mass, int i )
{
    fseek( binwrite, sizeof(fighter) * i, SEEK_SET );
    fwrite(fighter_mass + i, sizeof(fighter), 1, binwrite );
}


void read_from_binfile ( FILE *binread, fighter *fighter_mass, int i)
{
    fseek( binread, sizeof(fighter) * i, SEEK_SET );
    fread(fighter_mass + i, sizeof(fighter), 1, binread ); 
}



