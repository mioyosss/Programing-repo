#ifndef _STEHNIY_21_
#define _STEHNIY_21_


/**
 * @file lib.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Steghniy B.
 * @date 27-mar-2021
 * @version 0.1
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Создание структуры
typedef struct {	
	enum humantype { yes, no } human;
	enum gendertype { man, woman } gender;
	char name[20];
	int health;
	int power;
	enum boost { none, shield_10, shield_20, extra_life } bonus;
	enum clan { green, red, blue } clancolor;
} fighter_type;

typedef struct list_name {	// Создания списка на основе структуры
	fighter_type myfighter;
	struct list_name* next;
}list_type;


/**
 * @function create_list
 */
list_type* create_list(int N);

/**
 * @function read_from_file
 */
void read_from_file(list_type *head, FILE *read, int N);

/**
 * @function write_to_file
 */
void write_to_file(list_type *head, FILE *write, int N);

/**
 * @function output
 */
void output(list_type *head);

/**
 * @function find_object
 */
void find_object(list_type* head,int N);

/**
 * @fuction push_to_end
 */
void push_to_end(list_type *head);

/**
 * @function pop
 */
void pop(list_type **head);


#endif

