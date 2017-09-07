#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(void)
{
	int data[7][9];
	int j, i, temp;

	//initialization
	//for(j=0;j<7;j++)
	//	for(i=0;i<9;i++)
	//	{
	//		data[j][i]=0;
	//	}


	//input file
	FILE * fp;
	if( (fp=fopen("basis_input.txt","r")) == NULL)
	{
		printf("\nopenfile is failed\n");
	}
	else
	{
		for(j=0;j<7;j++)
		{
			for(i=0;i<9;i++)
			{
				fscanf(fp,"%d",&data[j][i]);
			}
			fscanf(fp,"\n");
		}
	fclose(fp);
	}
	//printf data[][]
	for(j=0;j<7;j++)
	{
		printf("\ndata[%]:", j);
		for(i=0;i<9;i++)
		{
			printf("\t%d", data[j][i]);
		}
	}
	printf("\n");
	
}