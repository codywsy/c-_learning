#include <stdio.h>

#define version 2

#if version == 1
int* twoSum(int *, int, int);


int main(void)
{
    const int size=3;
    int testArray[] = {3,2,4};
    int answerArray[2];
    int target = 6;
    int answerArray[2]={0,0};

    answerArray = twoSum(testArray, size, target);

//    int* answerArray = twoSum(testArray, size, target);

    printf("[%d,%d]", answerArray[0], answerArray[1]);
    free(answerArray);  //memory deallocation

    return 0;

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
   int* answer = (int*)malloc(sizeof(int)*2);
   //int answer[2]={0,0};

    for(int i=0;i<(numsSize-1);i++)
    {
        int temp;
        temp = target - nums[i];
        
        for(int j=i+1;j<numsSize;j++)
            if( temp==nums[j] )
            {
                answer[0]=i+1;
                answer[1]=j+1;
                
               return answer;
            }
    }

}
#elif version == 2

int main(void)
{
    const int size=3;
    int testArray[] = {3,2,4};
    int answer[2]={0,0};
    int target=6;
    int i, j, temp;

    for(i=0;i<(size-1);i++)
    {
        temp = target - testArray[i];
        
        for(j=i+1;j<size;j++)
            if( temp==testArray[j] )
            {
                answer[0]=i+1;
                answer[1]=j+1;
                
                printf("[%d,%d]", answer[0], answer[1]);

                return 0;
            }

    }  


}

#endif