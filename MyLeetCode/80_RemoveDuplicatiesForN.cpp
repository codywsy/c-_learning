#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

#define N 1

int removeDuplicates(int A[], int n) {
	if (n <= 2) return n;
	
	int index = N;
	for (int i = N; i < n; i++)
	{
		if (A[i] != A[index - N])
			A[index++] = A[i];
	}

	return index;

}

void printfArray(int A[], int n) {
	printf("{ ");
	for (int i = 0; i<n; i++){
		printf("%d ", A[i]);
	}
	printf("}\n");
}


void testSuite(int a[], int n){
	printfArray(a, n);
	n = removeDuplicates(a, n);
	printfArray(a, n);
	printf("------------------\n");
}

#define TEST(a) testSuite(a, sizeof(a)/sizeof(int))

int main(void)
{
	//map<string, int> wordCount;
	//string word;

	//cout << "Enter some words(Ctrl+Z to end):" << endl;
	//while (cin >> word)
	//	++wordCount[word];

	//cout << "word\t\t" << "times" << endl;
	//for (map<string, int> ::iterator iter = wordCount.begin(); iter != wordCount.end(); ++iter)
	//{
	//	cout << iter->first << "\t\t" << iter->second << endl;
	//}
	int A1[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	TEST(A1);
	int A2[] = { 1, 1, 1, 2, 2, 3, 3, 3, 4 };
	TEST(A2);





	return 0;

}