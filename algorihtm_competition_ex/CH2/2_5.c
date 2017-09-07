#include <stdio.h>

int main(void)
{
	FILE *fin;
	if ( (fin=fopen("InputFor2_5.txt", "rb")) == NULL)
	{
		printf("Can't open file!!\n\n");
	}

	int a, b, c;
	int count=0;

	while((fscanf(fin,"%d %d %d", &a, &b, &c)!=-1) && !(a==0&&b==0&c==0) )
	{
		double result=0.0;
		int c_temp;
		result =  (double)a/(double)b;	

		if(c<=100 && c>0)
		{
			int* dec = (int*)malloc(sizeof(int)*(c+2));	//dec[c+1] is used to rounding dec[c]
			dec[0]=0;
			
			c_temp = c;
			while(c_temp>=0)
			{
				result*=10;
				dec[c-c_temp+1] = (int)result%10;	//get the num in unit's place
//				printf("\n%d\n", dec[c-c_temp+1]);
				c_temp--;
			}

			result =  (double)a/(double)b;	
			printf("Case %d: %.0f.", ++count, result);	//print the integral number

			for( c_temp=1;c_temp<c;c_temp++)	//print the decimal number
			{
				printf("%d",dec[c_temp]);
			}
			printf("%d\n", dec[c_temp]+(dec[c_temp+1]/4));	//print the last decimal number with rounding

			free(dec);

		}
		else if(c==0)
		{
			printf("Case %d: %.0f\n", ++count, result);
		}
	}

	fclose(fin);
	return 0;
}