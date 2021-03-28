#include "lib.h"

void test_insert()
{
	char *s1 = (char *) malloc(sizeof(char));
	char *s2 = (char *) malloc(sizeof(char));

	s1 = "abrakadabra";
	s2 = "TEXT2";

	if ( strcmp(insert(s1, s2, 4), "abraTEXT2kadabra") == NULL )
		printf("\n Тест функции ''insert'' пройден успешно \n\n");
	else 
		printf("\n Тест функции ''insert'' не был пройден успешно \n\n");
}

void test_cutout()
{
	char *s1 = (char *) malloc(sizeof(char));

	s1 = "abrakadabra";

	if ( strcmp(cutout(s1, 5, 8), "abrabra") == NULL )
		printf("\n Тест функции ''cutout'' пройден успешно \n");
	else 
		printf("\n Тест функции ''cutout'' не был пройден успешно \n");
}

void test_add_struct()
{

	fighter *test_mass = (fighter*)malloc(sizeof(fighter));

	int n = 3;
	int powertest = 0;

	for ( int i = 0; i < n; i++ )
	{
		test_mass[i].power = 4;		
	}

	add_struct ( test_mass, n );

	for (  int i = 0; i < n+1; i++ )
	{
		powertest += test_mass[i].power;	
	}

	if ( powertest = 16 )
		printf("\n Тест функции ''add_struct'' пройден успешно \n");
	else 
		printf("\n Тест функции ''add_struct'' не был пройден успешно \n");
}

void test_delete_struct()
{
	fighter *test_mass = (fighter*)malloc(sizeof(fighter));

	int n = 3, struct_to_delete = 2;

	for ( int i = 0; i < n; i++ )
	{
		test_mass[i].power = 4;		
	}

	delete_struct ( test_mass, n, struct_to_delete );

	if ( test_mass[struct_to_delete].power == 0 )
		printf("\n Тест функции ''delete_struct'' пройден успешно \n");
	else 
		printf("\n Тест функции ''delete_struct'' не был пройден успешно \n");
}

int main()
{
	test_insert();
	test_cutout();

	test_add_struct();
	test_delete_struct();

	return 0;
}
