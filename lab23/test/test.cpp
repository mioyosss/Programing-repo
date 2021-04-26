#include "classes.h"

int test_clan()
{
	int n = 3;

	Fighter_Arr test_collection(3);

	test_collection.FillArr();



	int count = test_collection.SearchClan();

	if ( count == 2 )
		printf("\nТест проведен успешно\n");
	else 
		printf("\nТест не пройден\n");
}

int main()
{
	test_clan();
	return 0;
}
