#include <stdio.h>
#include <math.h>

int main(void)
{
	unsigned long int n, m;

    FILE *fin;
	if ( (fin=fopen("InputFor2_4.txt", "rb")) == NULL)
	{
		printf("Can't open file!!\n\n");
	}

	int count = 0;
	while((fscanf(fin, "%d %d", &n, &m) != -1) && !(n==0&&m==0))	//note 'short circult'
	{
		if(n<m)
		{
			unsigned long int i=n;
			double result=0.0;

			while(i<=m)
			{
				result += (1.0/pow((double)i,2.0)) ;
				i++;
			}

			printf("Case %d: %.5f\n", ++count, result);
		}
		else
		{
			printf("\ninput illegal\n");			
		}

	}

}