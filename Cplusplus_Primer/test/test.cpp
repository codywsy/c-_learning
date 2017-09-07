#include <stdio.h>

void printInBinary(int n) 
{ 
	if(n) 
		printInBinary(n/2); 
	else
	 return; 

	printf("%d", n & 0x1);

//	return;
} 

int main(void)
{
	unsigned int absExponent = 0;
	int exponent = -6;

	printInBinary(exponent);
	printf("\n");

	absExponent = (unsigned int) exponent;
	printInBinary(absExponent);

}