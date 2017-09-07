#include <stdio.h>

int main(void)
{
	int n, count;

	printf("please enter the value of n(no greater than 20): ");
	scanf("%d", &n);

	if (n <= 20)
	{
		count = 0;
		for (; n > 0 && n <= 20; n--)
		{
			int i;

			i = count;
			while (i > 0)
			{
				printf(" ");
				i--;
			}
			count++;

			for (i = 2 * (n - 1) + 1; i > 0; i--)
			{
				printf("#");
			}
			printf("\n");
		}
	}
	else if (n > 20)
	{
		printf("n is illegal\n");
	}
	getchar();


	return 0;
}