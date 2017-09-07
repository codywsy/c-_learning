//algorithm 1

int MaxSUbseqSum1( int A[], int N )
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