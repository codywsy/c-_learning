#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>	//stdbool.h only in C99, not in C98

bool isPalindrome(int x) {
    if(x<0) return false;
    else if(x==0) return true;
    else
    {
        int count, temp;
        int* ans=(int*)malloc(sizeof(int)*11);  //the size must greater than 10, but less than 20 
    
        //initilazation
        memset(ans,-1,sizeof(ans));
    
        //calculate the number of digital place and input in an array
        count = 1;
        temp = x/10;
        ans[count]=x%10;
        while(temp>0)
        {
            ++count;
            ans[count] = temp%10;
            temp /= 10;
        }
        
        //determine whether x is a palindrome number
        int p=1;
        for(int i=1; i<=(count+1)/2; i++)
        {
            if(ans[i]!=-1 && ans[count-i+1]!=-1 && ans[i]!=ans[count-i+1]) return false;
        }
        
        return true;
    }
    
}

int main(void)
{
	int x;
	printf("enter x:");
	scanf("%d", &x);

	printf("%d", isPalindrome(x));

	return 0;
}