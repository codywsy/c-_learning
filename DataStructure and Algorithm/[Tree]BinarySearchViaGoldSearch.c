/*****************
《云课堂@数据结构》第三讲树（上）的3.1 第4小节
二分法分割和黄金分割效果对比

******************/
#import <Foundation/Foundation.h>
 
typedef int(*func)(int a[], int K);
#define MAXREPEAT 10000000
#define MAXSIZE 1000000
 
int binarySearch (int a[], int K);
int hjfgSearch (int a[], int K);
void timeCost(func myFunc,int a[], int K);
void quickSort(int a[], int N);
void QuickSort(int a[],int p,int r);
 
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int K;
        int randomArray[MAXSIZE];
        for (int i = 0; i < MAXSIZE; i++) {
            randomArray[i] = (int)arc4random() % MAXSIZE;
        }
        quickSort(randomArray, MAXSIZE);
         
        NSLog(@"输入你想找的数：");
        scanf("%d", &K);
         
        NSLog(@"对半分用时：");
        timeCost(binarySearch, randomArray, K);
        NSLog(@"对半分结果：%d", binarySearch(randomArray, K));
         
        NSLog(@"黄金分割用时：");
        timeCost(hjfgSearch, randomArray, K);
        NSLog(@"黄金分割结果：%d", hjfgSearch(randomArray, K));
    }
    return 0;
}
 
int binarySearch (int a[], int K)
{
    int left, right, mid,Nought = -1;
    left = 0;
    right = MAXSIZE-1;
     
    while (left <= right) {
        mid = (left + right) / 2;
         
        if (a[mid] < K)
            left = mid+1;
         
        else if (a[mid] > K)
            right = mid-1;
        else return mid;
    }
    return Nought;
}
 
int hjfgSearch (int a[], int K)
{
    int left, right, mid,Nought = -1;
    left = 0;
    right = MAXSIZE-1;
     
    while (left <= right) {
        mid = (int)(left + 0.618 * (right - left));
         
        if (a[mid] < K)
            left = mid+1;
         
        else if (a[mid] > K)
            right = mid-1;
        else return mid;
    }
    return Nought;
}
 
void timeCost(func myFunc,int a[], int K)
{
    clock_t start, stop;
    double duration;
     
    start = clock();
    for (int i = 0; i < MAXREPEAT; i++) {
        myFunc(a, K);
    }
    stop = clock();
     
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("用时%f秒\n", duration);
}
 
void quickSort(int a[], int N)
{
    return QuickSort(a, 0, N-1);
}
 
void QuickSort(int a[],int p,int r)
{
    int Partition(int a[],int p,int r);
    if(p<r)
    {
        int q = Partition(a,p,r);
        QuickSort(a, p, q-1);
        QuickSort(a, q+1, r);
    }
}
 
int Partition(int a[],int p,int r)
{
    int i = p-1;
    int x = a[r-1];
    for(int j = p; j < r; j++)
    {
        if(a[j-1] <= x)
        {
            i = i+1;
            int temp;
            temp = a[j-1];
            a[j-1] = a[i-1];
            a[i-1] = temp;
        }
    }
    int temp;
    temp = a[i];
    a[i] = a[r-1];
    a[r-1] = temp;
    return i+1;
}