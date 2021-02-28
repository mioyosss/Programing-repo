#ifndef defend
#define defend

/**
 * @file lib.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Steghniy B.
 * @date 27-jan-2021
 * @version 0.1
 */


#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
						/* Общее задание */
typedef struct {
    enum humantype {yes, no} human;
    enum gendertype {man, woman} gender;
    char name[20];
    int health;
    int power;
    enum boost { none, shield_10, shield_20, extra_life } bonus;
    enum clan { green, red, blue} clancolor;
}fighter;



						/* Задание 4.1 */
/**
 * @function read_from_file
 */
int read_from_file( FILE *read, fighter *fighter_mass, int N );
/**
 * @function write_to_file
 */
int write_to_file(FILE *write, fighter *fighter_mass, int N);
/**
 * @function outputfunc
 */
void outputfunc(fighter *fighter_mass, int N);



						/* Задание 4.2 */
/**
 * @function sort
 */
int sort(fighter *fighter_mass, int N);
/**
 * @function sort_alphabet
 */
int sort_alphabet(fighter *fighter_mass, int N, int sorttype);
/**
 * @function sort_ascending
 */
int sort_ascending(fighter *fighter_mass, int N, int sorttype);
/**
 * @function sort_enum
 */
int sort_enum(fighter *fighter_mass, int N, int sorttype);



						/* Задание 4.3 */
/**
 * @function searchclan
 */						
short int searchclan(fighter *mass, int N);


						/* Задание 4.4 */
/**
 * @function randfunc
 */
void randfunc(fighter *fighter_mass, int N);

/**
 * @function write_to_binfile
 */
void write_to_binfile ( FILE *binwrite, fighter *fighter_mass, int i ); 

/**
 * @function read_from_binfile
 */	
void read_from_binfile ( FILE *binread, fighter *fighter_mass, int i );

#endif
