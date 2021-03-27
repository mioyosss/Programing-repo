#include "lib.h"

/**
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Steghniy B.
 * @date 27-mar-2021
 * @version 0.1
 */

//Функция для создания узлов для списка
list_type* create_list(int N)
{
	list_type* node = NULL;
	list_type* head = NULL;
	list_type* new_node = NULL;
	
	for (int i = 0; i < N; i++)  // Цикл для создания узлов для списка 
	{
		new_node = (list_type*)malloc(sizeof(list_type)); // выделение места место под один узел списка

		if (head == NULL)			// сохраняем "голову" списка
			head = new_node;
		else
			node->next = new_node;			

		node = new_node;

		node->next = NULL;				// объявляем наличие следующего узла списка
	}
	return head;
}

	// Функция для чтения с файла и записи в список
	void read_from_file(list_type *head, FILE *read, int N){

	list_type *node = head;
	
	// Буферные переменные для сравнения и записи в список
	char human[20];
	char gender[20];
	char bonus[20];
	char clancolor[20];
	
	for(int i = 0; i < N; i++){
	
		fscanf(read,"%s", human );
	
		if ( strcmp(human, "yes") == 0 )
			node->myfighter.human = 0;

		if ( strcmp(human, "no") == 0 )
			node->myfighter.human = 1;
	
		fscanf(read,"%s", gender );

        	if ( strcmp(gender, "man") == 0 )
			node->myfighter.gender = 0;

        	if ( strcmp(gender, "woman") == 0 )
			node->myfighter.gender = 1;
	
		fscanf(read,"%s", node->myfighter.name );
	
		fscanf(read,"%d", &node->myfighter.health);
	
		fscanf(read,"%d", &node->myfighter.power);
	
		fscanf(read,"%s", bonus );

        	if ( strcmp(bonus, "none") == 0 )
        		node->myfighter.bonus = 0;

		if ( strcmp(bonus, "shield_10") == 0 )
			node->myfighter.bonus = 1;
            
		if ( strcmp(bonus, "shield_20") == 0 )
			node->myfighter.bonus = 2;
	
		if ( strcmp(bonus, "extra_life") == 0 )
			node->myfighter.bonus = 3;
	
		fscanf(read,"%s", clancolor );
		
		if ( strcmp(clancolor, "green") == 0 )
			node->myfighter.clancolor = 0;
	
		if ( strcmp(clancolor, "red") == 0 )
			node->myfighter.clancolor = 1;
            
		if ( strcmp(clancolor, "blue") == 0 )
			node->myfighter.clancolor = 2;
           
		node = node->next;
		}
	}

	// Функция для записи списка в файл
	void write_to_file(list_type *head, FILE *write, int N){
	
	list_type *node = head;

	for(int i = 0; i < N; i++){
	fprintf(write, "Боец - человек: %s\nБоец мужчина или женщина: %s\nИмя бойца: %s\nКоличество очков жизни бойца: %d\nКоличество очков силы бойца: %d\n",node->myfighter.human == 0 ? "да":"нет", node->myfighter.human == 0 ? "мужчина":"женщина", node->myfighter.name, node->myfighter.health, node->myfighter.power);
	
		if(node->myfighter.bonus == 0)
			fprintf(write,"Бонус: нет\n");
		if(node->myfighter.bonus == 1)
			fprintf(write,"Бонус: защита 10\n");
		if(node->myfighter.bonus == 2)
			fprintf(write,"Бонус: защита 20\n");
		if(node->myfighter.bonus == 3)
			fprintf(write,"Бонус: дополнительная жизнь\n");
	
		if(node->myfighter.clancolor == green)
			fprintf(write,"Клан бойца: зеленый\n\n");
		if(node->myfighter.clancolor == red)
			fprintf(write,"Клан бойца: красный\n\n");
		if(node->myfighter.clancolor == blue)
			fprintf(write,"Клан бойца: синий\n\n");
	
		node = node->next;
		}
	}

	// Функция для вывода списка в консоль
	void output(list_type *head){
	// Чтобы вывести наши заполненные поля, нужно создать узел, который сначала мы приравняем голове списка 
	list_type* node = head;
	
	int count = 1;
	printf("────────────────────────────────────────────────────────────────────────\n");
	printf("     Человек \tПол  \t  Жизни\t Урон  \t Бонус      Клан \tИмя \n────────────────────────────────────────────────────────────────────────\n");
	while (node != NULL){     // пока узел не является концом списка - выполняем следующие действия:
		printf("[%2d]", count++);
	
		if(node->myfighter.human == 0)
			printf(" Да         ");
		if(node->myfighter.human == 1)
			printf(" Нет        ");
		if(node->myfighter.gender == 0)
			printf("Мужчина   ");
		if(node->myfighter.gender == 1)
			printf("Женщина   ");
	
  	   	printf("%d     ", node->myfighter.health);
  	        printf("%d      ", node->myfighter.power );
	
		if(node->myfighter.bonus == 0)
			printf("Нет        ");
		if(node->myfighter.bonus == 1)
			printf("Защита 10  ");
		if(node->myfighter.bonus == 2)
			printf("Защита 20  ");
		if(node->myfighter.bonus == 3)
			printf("Доп. жизнь ");
       
		if(node->myfighter.clancolor == 0)
			printf("Зеленый     ");
		if(node->myfighter.clancolor == 1)
			printf("Красный     ");
		if(node->myfighter.clancolor == 2)
			printf("Синий       ");
			
		printf("%s     ", node->myfighter.name);
		
		printf("\n");
		
		
		//Переход к следующему узлу за счет указателя на следующий элемент
		node = node->next;
		}
		printf("────────────────────────────────────────────────────────────────────────\n");
	}
	
	// Функция по поиску объекста за заданым критерием
	void find_object(list_type* head,int N){
	
	list_type* node = head;
	
	// Переменны для выбора критерия поиска
	int if_flag;
	int if_flag1;
	// Счетчик
	int count = 0;	
	int count_not_found = 0;
	printf("\n Критерии для поиска объекта: \n [1] Человек \n [2] Пол \n [3] Кол-во единиц жизни \n [4] Кол-во единиц урона \n [5] Бонус \n [6] Клан \n [7] Имя \n Введите номер критерия: ");
	scanf("%d", &if_flag);
	printf("\n");
	

	if(if_flag == 1){
	
		printf(" Доступные значения: \n [1] Да \n [2] Нет \n\n");
		printf(" Введите значение для поиска: ");
		scanf("%d", &if_flag1);
		printf("\n");
		
		
		if(if_flag1 == 1){
			printf(" Значение ''Да'' найдено в узлах под номерами: ");	
			for(int i = 0; i < N; i++){
				if(node->myfighter.human == 0){
				printf(" %d", count+1);
				count_not_found++;
				}
			count++;
			node = node->next;
			}
			if(count_not_found == 0)
			printf("такого значения нет в списке"); 
		}
		
		if(if_flag1 == 2){
			printf(" Значение ''Нет'' найдено в узлах под номерами: ");	
			for(int i = 0; i < N; i++){	
				if(node->myfighter.human == 1){
				printf("% d", count+1);
				count_not_found++;
				}
			count++;
			node = node->next;
			}
			if(count_not_found == 0)
			printf("такого значения нет в списке"); 
		}
	}
	
	if(if_flag == 2){
		printf("\n Доступные значения: \n [1] Мужчина \n [2] Женщина \n\n");
		printf(" Введите значение для поиска: ");
		scanf("%d", &if_flag1);
		printf("\n");
		if(if_flag1 == 1){
			printf(" Значение ''Мужчина'' найдено в узлах под номерами: ");	
			for(int i = 0; i < N; i++){
				if(node->myfighter.gender == 0){
				printf(" %d", count+1);
				count_not_found++;
				}
			count++;
			node = node->next;
			}
			if(count_not_found == 0)
			printf("такого значения нет в списке"); 
		}
		
		if(if_flag1 == 2){
			printf(" Значение ''Женщина'' найдено в узлах под номерами:");	
			for(int i = 0; i < N; i++){	
				if(node->myfighter.gender == 1){
				printf("% d", count+1);
				count_not_found++;
				}
			count++;
			node = node->next;
			}
			if(count_not_found == 0)
			printf("такого значения нет в списке"); 
		}
	}
	
	if(if_flag == 3){
		
		printf(" Введите значение: ");
		scanf("%d", &if_flag1);
		printf("\n");
		printf(" Значение ''Кол-во единиц жизни ─ %d'' найдено в узлах под номерами: ", if_flag1); 
		for(int i = 0; i < N; i++){
			if(if_flag1 == node->myfighter.health){
			printf("%d ", count+1);
			count_not_found++;
			}
			count++;		
			node = node->next;
		}
		if(count_not_found == 0)
		printf("такого значения нет в списке"); 
	}
	
	if(if_flag == 4){
	
		printf(" Введите значение: ");
		scanf("%d", &if_flag1);
		printf("\n");
		printf(" Значение ''Кол-во единиц урона ─ %d'' найдено в узлах под номерами: ", if_flag1); 
		for(int i = 0; i < N; i++){
			if(if_flag1 == node->myfighter.power){
			printf("%d ", count+1);
			count_not_found++;
			}
			count++;		
			node = node->next;
		}
		if(count_not_found == 0)
		printf("такого значения нет в списке");
	}
	
	if(if_flag == 5){
	
	printf("\n Доступные значения: \n [1] Нет \n [2] Защита 10 \n [3] Защита 20 \n [4] Дополнительная жизнь \n\n");
		printf(" Введите значение для поиска: ");
		scanf("%d", &if_flag1);
		printf("\n");
		if(if_flag1 == 1){
			printf(" Значение ''Нет'' найдено в узлах под номерами:");	
			for(int i = 0; i < N; i++){
				if(node->myfighter.bonus == 0){
				printf(" %d", count+1);
				count_not_found++;
				}
			count++;
			node = node->next;
			}
			if(count_not_found == 0)
			printf(" такого значения нет в списке"); 
		}
		
		if(if_flag1 == 2){
			printf(" Значение ''Защита 10'' найдено в узлах под номерами:");	
			for(int i = 0; i < N; i++){	
				if(node->myfighter.bonus == 1){
				printf("% d", count+1);
				count_not_found++;
				}
			count++;
			node = node->next;
			}
			if(count_not_found == 0)
			printf(" такого значения нет в списке"); 
		}
	
		if(if_flag1 == 3){
			printf(" Значение ''Защита 20'' найдено в узлах под номерами:");	
			for(int i = 0; i < N; i++){
				if(node->myfighter.bonus == 2){
				printf(" %d", count+1);
				count_not_found++;
				}
			count++;
			node = node->next;
			}
			if(count_not_found == 0)
			printf(" такого значения нет в списке"); 
		}
		
		if(if_flag1 == 4){
			printf(" Значение ''Дополнительная жизнь'' найдено в узлах под номерами:");	
			for(int i = 0; i < N; i++){
				if(node->myfighter.bonus == 3){
				printf(" %d", count+1);
				count_not_found++;
				}
			count++;
			node = node->next;
			}
			if(count_not_found == 0)
			printf(" такого значения нет в списке"); 
		}
	}
	
	if(if_flag == 6){
	
	printf("\n Доступные значения: \n [1] Красный \n [2] Зеленый \n [3] Синий \n\n");
		printf(" Введите значение для поиска: ");
		scanf("%d", &if_flag1);
		printf("\n");
		if(if_flag1 == 1){
			printf(" Значение ''Красный'' найдено в узлах под номерами:");	
			for(int i = 0; i < N; i++){
				if(node->myfighter.clancolor == 1){
				printf(" %d", count+1);
				count_not_found++;
				}
			count++;
			node = node->next;
			}
			if(count_not_found == 0)
			printf(" такого значения нет в списке"); 
		}
		
		if(if_flag1 == 2){
			printf(" Значение ''Зеленый'' найдено в узлах под номерами:");	
			for(int i = 0; i < N; i++){	
				if(node->myfighter.clancolor == 0){
				printf("% d", count+1);
				count_not_found++;
				}
			count++;
			node = node->next;
			}
			if(count_not_found == 0)
			printf(" такого значения нет в списке"); 
		}
	
		if(if_flag1 == 3){
			printf(" Значение ''Синий'' найдено в узлах под номерами:");	
			for(int i = 0; i < N; i++){
				if(node->myfighter.clancolor == 2){
				printf(" %d", count+1);
				count_not_found++;
				}
			count++;
			node = node->next;
			}
			if(count_not_found == 0)
			printf("такого значения нет в списке"); 
		}
	}
	
	if(if_flag == 7){
	
		printf(" Доступные имена: \n");
		for(int i = 0; i < N; i++){
			printf(" %s;",node->myfighter.name);
			node = node->next;
		}
		printf("\n\n Введите имя для поиска: ");
		char name_flag[20];
		scanf("%s", name_flag);
		printf("\n");
		printf(" Имя ''%s'' найдено в узлах под номерами: ", name_flag); 
	
		node = NULL;
		list_type* node = head;
		
		for(int i = 0; i < N; i++){
			if( strcmp(name_flag, node->myfighter.name) == 0){
				printf("%d ", count+1);
				count_not_found++;
			}
			count++;		
			node = node->next;
		}	
		if(count_not_found == 0)
			printf(" такого имени нет в списке"); 
	}
	printf("\n\n");
}

	void push_to_end(list_type *head, int N){
	
	list_type *node = head;
	
	
	
	}
