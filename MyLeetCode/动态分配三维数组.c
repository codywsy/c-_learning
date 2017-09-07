#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *** Create3DActiveArray(int ***pArr, int x, int y, int z)
{
	int i, u, v;
	pArr = (int ***)malloc( x*sizeof(int **) );	//apply for x 3D pointer

	for(i=0;i<x;i++)
	{
		pArr[i] = (int **)malloc( y*sizeof(int*) );

		for(u=0;u<y;u++)
		{
			pArr[i][u] = (int *)malloc( z*sizeof(int) );
			for(v=0;v<z;v++)
			{
				pArr[i][u][v]=i*100+u*10+v;
			}
		}
	}

	return pArr;
}


void Free3DActiveArray(int ***pArr, int x, int y, int z)
{
	int i, u, v;

	for(i=0;i<x;i++)
	{
		for(u=0;u<y;u++)
		{
			free(pArr[i][u]);
			pArr[i][u]=0;
		}

		free(pArr[i]);
		pArr[i]=0;
	}

	free(pArr);

}



void main(void)
{
	int i, u, v;
	int *** q_temp = NULL;
	q_temp = Create3DActiveArray(q_temp,2,3,4);

	for(i=0;i<2;i++)
	{
		printf("\nq_temp[%d]:\n", i);
		for(u=0;u<3;u++)
		{
			for(v=0;v<4;v++)
			{
				printf("\t%d", q_temp[i][u][v]);
			}
			printf("\n");
		}
		printf("\n");
	}

	Free3DActiveArray(q_temp,2,3,4);

	for(i=0;i<2;i++)
	{
		printf("\nq_temp[%d]:\n", i);
		for(u=0;u<3;u++)
		{
			for(v=0;v<4;v++)
			{
				printf("\t%d", q_temp[i][u][v]);
			}
			printf("\n");
		}
		printf("\n");
	}

	getchar();

}