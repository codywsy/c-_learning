/**
 * Return an array of arrays of size *returnSize.	
 * The sizes of the arrays are returned as *columnSizes array.	
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
	int **result;	//输出结果
	*returnSize = numRows;	//将行数放置到*returnSize，疑问是为什么要用一维数组来存一个整数
	//应该这么想，returnSize是一个指向整型变量的指针，对这个指针指向的变量取值为1

	//initialization
	*(columnSizes) = (int *) malloc(sizeof(int)*numRows);	//columnSize 是一个指向整型数组的指针，而只开辟第一个指针指向的整型数组作为使用，数组大小为行数
	//*columnSize所指向的整型数组的作用是存放每一行的变量数目
	result = (int **) malloc(sizeof(int *)*numRows);

	//start
	for(int i=0; i<numRows; i++)
	{
		*(*columnSizes+i) = i+1;	//记录第i行的变量数目
		*(result+i) = (int *)malloc(sizeof(int)*(i+1));	//第i行开辟i+1个空间

		for(int j=0; j<=i; j++)
		{
			if(j==0 || j==i)	//每行的首尾两个变量置1
			{
				*(*(result+i)+j) = 1;
			}
			else
			{
				*(*(result+i)+j) = *(*(result+i-1)+j-1) + *(*(result+i-1)+j);	//本行的元素等于上一行的两个元素之和
			}
		}
	}

	return result;
}


