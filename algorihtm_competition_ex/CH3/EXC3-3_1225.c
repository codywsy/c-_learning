#include <stdio.h>
#include <string.h>
#define maxn 10

int main()
{
    int T;
    int n;
    int count[maxn];
    scanf("%d",&T);

    while(T--) 
    {
        scanf("%d", &n);
        memset(count,0,sizeof(count));
        
        for(int i=0; i<=n; i++)
         {
            int temp = i;
            while(temp>0) 
            {
                ++count[temp%10];
                temp /= 10;
            }
        }

        for(int i=0; i<maxn; i++) //output type has a blind point
        {
            if(i<9)
            {
                printf("%d ", count[i]);
            }
            else
            {
                printf("%d\n", count[i]);   //the last output num doesn't have a fllowing space
            }
        }
//        printf("\n");
    }

    return 0;
}