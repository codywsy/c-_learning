#include <stdio.h>

int MaxSubseqSum1(int *,int);

void main(void)
{
  int A[10];
  int i, size;
  
  printf("please input the size of array:");
  scanf("%d",&size);
  printf("please input the element of array:");
  for(i=0;i<size;i++)
    scanf("%d",&A[i]);

  printf("\narray =");
  for(i=0;i<size;i++)
    printf("\t%d",A[i]);
  printf("\n\nthe MaxSum = %d",MaxSubseqSum1(A,size));
  
}


int MaxSubseqSum1( int A[], int N )
{
  int ThisSum, MaxSum = 0;
  int i, j, k;
  for( i=0; i<N; i++) {
    for( j=i; j<N; j++) {
      ThisSum = 0;
      for(k=i;k<j;k++)
        ThisSum += A[k];
      if( ThisSum > MaxSum)
        MaxSum = ThisSum;
        
    }
  }  
  return MaxSum;    
}
  
  