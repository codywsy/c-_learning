#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,x;

	for(x=100,i=0; x<=999; x++)
	{
		int a,b,c;
		float temp=0.0;

		a = x/100;
		b = (x/10)%10;
		c = x%10;

		temp += pow( (float)a,3.0 );
		temp += pow( (float)b,3.0 );
		temp += pow( (float)c,3.0 );

		if(temp==x)
		{
			printf("\nNo.%d = %d", i++, x);
		}

	}

	return 0;

}