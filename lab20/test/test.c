#include "lib.h"

void test_insert()
{
	DEBUG;
	clock_t begin = clock();
	char *s1 = (char *) malloc(sizeof(char));
	char *s2 = (char *) malloc(sizeof(char));

	s1 = "abrakadabra";
	s2 = "TEXT2";

	if ( strcmp(insert(s1, s2, 4), "abraTEXT2kadabra") == NULL )
		printf("\n Тест функции ''insert'' пройден успешно \n\n");
	else 
		printf("\n Тест функции ''insert'' не был пройден успешно \n\n");
	clock_t endtime = clock();
	double time_spent = (double)(endtime - begin) / CLOCKS_PER_SEC;

	printf("\n\n Тест ''%s'' продлился: %f сек.\n\n",__FUNCTION__, time_spent);
}

void test_cutout()
{
	DEBUG;
	clock_t begin = clock();
	char *s1 = (char *) malloc(sizeof(char));

	s1 = "abrakadabra";

	if ( strcmp(cutout(s1, 5, 8), "abrabra") == NULL )
		printf("\n Тест функции ''cutout'' пройден успешно \n");
	else 
		printf("\n Тест функции ''cutout'' не был пройден успешно \n");
	clock_t endtime = clock();
	double time_spent = (double)(endtime - begin) / CLOCKS_PER_SEC;

	printf("\n\n Тест ''%s'' продлился: %f сек.\n\n",__FUNCTION__, time_spent);
}

void test_add_struct()
{
	DEBUG;
	clock_t begin = clock();
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
	clock_t endtime = clock();
	double time_spent = (double)(endtime - begin) / CLOCKS_PER_SEC;

	printf("\n\n Тест ''%s'' продлился: %f сек.\n\n",__FUNCTION__, time_spent);
}

void test_delete_struct()
{
	DEBUG;
	clock_t begin = clock();
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
	clock_t endtime = clock();
	double time_spent = (double)(endtime - begin) / CLOCKS_PER_SEC;

	printf("\n\n Тест ''%s'' продлился: %f сек.\n\n",__FUNCTION__, time_spent);
}

int main()
{
	clock_t begin = clock();
	test_insert();
	test_cutout();

	test_add_struct();
	test_delete_struct();
	clock_t endtime = clock();
	double time_spent = (double)(endtime - begin) / CLOCKS_PER_SEC;

	printf("\n\n\n Все тесты продлились: %f сек.\n\n", time_spent);

	return 0;
}
