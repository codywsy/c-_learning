#include <stdio.h>
#include <string.h>
#define maxn 10005
int ans[maxn];

int main(void)
{
	int T, n;

	//calculate the table
	memset(ans,0,sizeof(ans));
	for(int m=1;m<maxn;m++)
	{
		int x=m, y=m;
		while(x>0)
		{
			y+= x%10;
			x /= 10;
		}

		if( ans[y]==0 || m<ans[y] )
		{
			ans[y]=m;
		}
	}

	//input nums and print out the generating num of input num
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}

	return 0;

}