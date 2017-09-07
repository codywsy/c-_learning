#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>	//stdbool.h only in C99, not in C98

int reverse(int x) {
    if(x>=0 && x<10) return x;
    else
    {
        //catch x in ans[]
        int i;
        int temp = abs(x);
        int count=0;
        int ans[11];
        memset(ans,-1,sizeof(ans));

        while(temp%10==0)
        {
            temp /= 10;
        }

        while(temp>0)
        {
            ++count;
            ans[count] = temp%10;
            temp /= 10;
        }

        if(count==10)
        {
            //catch maxvalue in max[]
            int maxvalue = INT_MAX;
            int max[11];
            memset(max,-1,sizeof(max));
            i=0;

            while(maxvalue>0)
            {
                ++i;
                max[i] = maxvalue%10;
                maxvalue /= 10;
            }

            //contrasting the value of ans[i] and maxvalue[i];
            for(i=1; i<=count;i++)
                if((ans[i]!=-1) && (ans[i]>max[count-i+1]) )
                {
                   return 0;
                }
                else if(ans[i]<=(max[count-i+1]-1) )
                {
                    break;
                }
        }

        //or output the reverse num
        int result = 0;
		int div;
        i=count;
        while(ans[i]==0)
        {
            --i;
        }

        div = 1;
        while(i>0)
        {
            result += ans[i] * div;
            div *= 10;
            --i;
        }

        //determine the sign of num
        if(x>0)
        {
            return result;
        }
        else if(x<0)
        {
            return -(result);
        }

    }    
}

int main(void)
{
	int x;
//	printf("enter x:");
//	scanf("%d", &x);
    x=1534236469;

	printf("%d", reverse(x));

	return 0;
}