#include <iostream>
using namespace std;

void Swap(char* A, char* B)
{
	char temp = *A;
	*A = *B;
	*B = temp;
}

void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
	{
		cout << pStr << endl;
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			Swap(pBegin, pCh);

			Permutation(pStr, pBegin+1);

			Swap(pBegin, pCh);
		}
	}

}


void Permutation(char* pStr)
{
	if (pStr == NULL)
		return;

	Permutation(pStr, pStr);
}

int main(void)
{
	char pStr[] = "abc";
	Permutation(pStr);

	return 0;
}