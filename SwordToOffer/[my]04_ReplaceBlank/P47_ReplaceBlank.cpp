#include <stdio.h>
#include <string.h>

void ReplaceBlank(char string[], int length)
{
	//先检查输入的字符串是否合格
	if(string == NULL || length <= 0)
		return;

	//查看string中的空格数，确定新字符串大小
	//originalLength 为string的实际长度
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while(string[i]!='\0')
	{
		++ originalLength;

		if(string[i] == ' ')
			++ numberOfBlank;

		++ i;
	}

	//开始转换
	//newLength为把空格转换成'%20'之后的长度
	int newLength = originalLength + 2 * numberOfBlank;
	if( newLength> length )
		return;

	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if(string[indexOfOriginal] == ' ')
		{
			string[indexOfNew --] = '0';
			string[indexOfNew --] = '2';
			string[indexOfNew --] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}

		-- indexOfOriginal;
	}

}

void Test(char* testName, char string[], int length, char expected[])
{
	if(testName != NULL)
		printf("%s begin:", testName);

	ReplaceBlank(string, length);

	if(expected == NULL && string == NULL)
		printf("Passed.\n");
	else if(expected == NULL && string != NULL)
		printf("Failed.\n");
	else if(strcmp(expected, string) == 0)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

void Test1()
{
	const int length = 100;
	char string[length] = "we are happy";
	Test("Test1", string, 100, "we%20are%20happy");
}

void Test2()
{
	const int length = 100;
	char string[length] = " hello  world ";
	Test("Test2", string, length, "%20hello%20%20world%20");
}

void Test3()
{
	const int length = 100;
	char string[length] = "wearehappy";
	Test("Test3", string, length, "wearehappy");
}

void Test4()
{
	const int length = 100;
	char string[length] = "   ";
	Test("Test4", string, length, "%20%20%20");
}

void Test5()
{
	Test("Test5", NULL, 0, NULL);
}

void Test6()
{
    const int length = 100;

    char string[length] = "";
    Test("Test6", string, length, "");
}

int main(void)
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}