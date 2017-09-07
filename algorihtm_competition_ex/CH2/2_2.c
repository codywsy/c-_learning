// execrise for CH2

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<string.h> 

#define check
//#define fileGets
#define fileScanf

//#define dataSize 6


int main(void)
{
//  char *s=(char *)malloc(dataSize*sizeof(char));	//开一个size为5的字符数组指针来存放读入数据
//	char s[dataSize];
//	char *p;
    int count;

    FILE *fin;
	if ( (fin=fopen("InputFor2_2.txt", "rb")) == NULL)
	{
		printf("Can't open file!!\n\n");
	}

    //用文件指针打开InputFor2_2.txt作为输入文件
	//for (int j = 0; j < dataSize; j++)
	//{
	//	s[j] = 0;
	//}

	count = 0;

#ifdef fileScanf
	int a, b, c;

	while (fscanf(fin, "%d %d %d", &a, &b, &c) != -1)
	{
		int x;
		int flag = 0;
		
		for (x = 10; x <= 100; x++)
			if ((x - a) % 3 == 0)
			{
				if ((x - b) % 5 == 0)
				{
					if ((x - c) % 7 == 0)
					{
						printf("Case %d: %d\n\n", count++, x);

						flag = 1;
						break;
					}

					if (flag == 1)
					{
						break;
					}
				}

				if (flag == 1)
				{
					break;
				}
			}

		if (x == 101)
		{
			printf("Case %d: No answer\n\n", count++);
		}
	}

#endif


#ifdef fileGet

    while(fgets(s,dataSize,fin)!=NULL)
    {
        int x;

        #ifdef check
        int i;
        printf("\ns_%d:", count);
        for(i=0;i<dataSize;i++)
        {
            printf("\ts[%d]=%c", i, s[i]);
        }
        printf("\n\n");
        #endif 

        for(x=10;x<=100;x++)
            if( (x-s[0])%3 == 0 )
                if( (x-s[2])%5 == 0 )
                    if(	(x-s[4])%7 == 0 )
                    {
                        printf("Case %d: %d\n\n", count++, x);
                    }

            if(x==101)
            {
                printf("Case %d: No answer\n\n", count++);
            }		
    }
#endif

    //按照格式输出数据, 要加入计数器来计算行数
    //printf("Case %d：%d", count++, sum);

	fclose(fin);


    return 0;
}
