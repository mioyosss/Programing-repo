#ifndef _STEHNIY_21_
#define _STEHNIY_21_


/**
 * @file lib.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Steghniy B.
 * @date 08-mar-2021
 * @version 0.1
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG printf(" FUCNTION: ''%s''  - %s  /  %s\n\n",  __FUNCTION__, __DATE__, __TIME__ )

typedef struct {
    enum humantype {yes, no} human;
    enum gendertype {man, woman} gender;
    char name[20];
    int health;
    int power;
    enum boost { none, shield_10, shield_20, extra_life } bonus;
    enum clan { green, red, blue} clancolor;
}fighter;

/**
 * @function insert
 */
char* insert(char* s1, char* s2, int pos);

/**
 * @function cutout
 */
char* cutout(char* s1, int start, int end);

/**
 * @function filling
 */
void* filling(fighter *fighter_mass, int n);

/**
 * @function add_struct
 */
void add_struct( fighter * fighter_mass, int n);

/**
 * @function delete_struct
 */
void delete_struct( fighter * fighter_mass, int n, int struct_to_delete);

#endif

