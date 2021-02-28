#include "lib.h"

unsigned short test_clan()
{
	int n = 3;

	fighter test[n];

	test[0].clancolor = blue;
	test[1].clancolor = blue;
	test[2].clancolor = green;


	int count = searchclan (test, n);

	if ( count == 2 )
		printf("\nTest: successful\n");
	else 
		printf("\nTest: failed\n");
}

int main()
{
	test_clan();
	return 0;
}
