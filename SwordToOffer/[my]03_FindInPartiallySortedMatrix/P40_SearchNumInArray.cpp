bool Find(int *matrix, int rows, int cloumns, int number)
{
	bool found = false;

	if(matrix != NULL && rows > 0 && cloumns > 0)
	{
		int row = 0;
		int cloumn  = cloumns - 1;
		while(row < rows && cloumns >= 0)
		{
			if(matrix[row * cloumns + cloumn] == number)
			{
				found = true;
				break;
			}
			else if(matrix[row * cloumns + cloumn] > number)
			{
				-- cloumn;
			}
			else
			{
				++ row;
			}
		}
	}

	return found;
}

//================测试代码======================
void Test(char* testName, int* matrix, int rows, int cloumns, bool expected)
{
	if(testName != NULL)
		printf("%s begin: ", testName);

	bool result = Find(matrix, rows, cloumns, number);
	if(result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}