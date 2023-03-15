#include <stdio.h>
#include <string.h>

/*  compare num with 0b1, therefore LSB of n compares with 1, add "&& comparison" 
	results to cnt (result will be 1 or 0), then bit shift right so next digit can
	be compared.
*/

int count_ones_pos (int n)
{
	int cnt = 0;
	while (n != 0)
	{	
		cnt = cnt + (n & 1); 
		n = n >> 1;
	}
	return cnt;
}

/*  compare num with mask: set to 1. If comparison is equal to the mask then the 
	number has a bit at that location. Then, shift the mask to the left so that the
	rest of the spots can be checked.
*/

int count_ones_neg (int n)
{
	int cnt = 0;
	int mask = 1;
	while (mask != 0)
	{	
		if (((mask & n)) == mask) 
		{
			cnt += 1;
		}
		mask = mask << 1;
	}
	return cnt;
}

int main ()
{
	int n;
	int ones_cnt;
	char response = 'y';

	printf("Welcome to the CountOnes program. \n");

	while (response != 'n') 
	{
		printf("\n");
		printf("Please enter a number: ");
		scanf(" %d", &n);

		if (n < 0) ones_cnt = count_ones_neg(n);
		else ones_cnt = count_ones_pos(n);
		printf("The number of bits set is: %d\n", ones_cnt);

		printf("Continue (y/n)?: ");
		scanf(" %s", &response);
	}
	printf("%s", "Exiting\n");

	return 0;
}
