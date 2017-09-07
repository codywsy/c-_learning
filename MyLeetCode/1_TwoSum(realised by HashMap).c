//C code 

//有两个函数 twoSum是解法一； twoSum_hash是解法二
#include <stdio.h>
#include<stdlib.h>
#define PRIME 271
int *twoSum(int numbers[], int n, int target)
{
    if ((numbers == NULL)|(n < 2))
    {
        return NULL;
    }
    int index1;
    int index2;
    int* ret = (int*)malloc(sizeof(int)*2);
    if (NULL == ret)
    {
        printf("memory allocation for ret failed!\n");
        return NULL;
    }
    for (index1 = 0; index1 < n; ++index1)
    {
        for (index2 = index1 + 1; index2 < n; ++index2)
        {
            int sum_tmp = numbers[index1] + numbers[index2];
            if (sum_tmp == target)
            {
                ret[0] = index1 + 1;
                ret[1] = index2 + 1;
                return ret;
            }
        }
    }
    return NULL;
}
//second method
typedef struct linkedListNode* plistNode;
typedef struct linkedListNode
{
    int index;
    plistNode next;
}listNode;
void hashTableFree(plistNode hashTable, int primeNumber)    //primeNumer is the size of hashTable index
{
    int index = 0;
    for (index = 0; index < primeNumber; ++index)   //search the Node with 'primeNumber-1'
    {
        plistNode tail = hashTable[index].next;
        while(NULL != tail) //search the last node of hashTable[index]
        {
            plistNode tmp = tail;
            tail = tail->next;
            free(tmp);
        }
    }
    free(hashTable);
}
int *twoSum_hash(int numbers[], int n, int target)
{
    if ((numbers == NULL)|(n < 2))
    {
        return NULL;
    }
    int index = 0;
    //create a hash table
    int primeNumber = PRIME;    //PRIME == 271
    plistNode hashTable = (plistNode)malloc(sizeof(listNode)*primeNumber);
    if (NULL == hashTable)
    {
        printf("memory allocation for hashTable failed!\n");
        return NULL;
    }
    //initialise the hash table
    for (index = 0; index < primeNumber; ++index)
    {
        hashTable[index].index = -1;
        hashTable[index].next = NULL;
    }
    //assign numbers to the hash table
    for (index = 0; index < n; ++index)
    {
        int bias = abs(numbers[index]%primeNumber);
        if (-1 == hashTable[bias].index)
        {
            hashTable[bias].index = index;
        }else //occupied
        {
            plistNode tail = hashTable[bias].next;
            tail = (plistNode )malloc(sizeof(listNode));
            if (NULL == tail)
            {
                printf("memory allocation for tail failed!\n");
                hashTableFree(hashTable, primeNumber);
                return NULL;
            }
            tail->index = index;
            tail->next = hashTable[bias].next;
            hashTable[bias].next = tail;
        }
    }
    //searching
    int* ret = (int*)malloc(sizeof(int)*2);
    for (index = 0; index < n; ++index )
    {
        int bias = abs((target - numbers[index])%primeNumber);  
        if (-1 == hashTable[bias].index) // this bias doesn't exist
        {
            continue;
        }
        if ((numbers[hashTable[bias].index] == (target - numbers[index])) & (hashTable[bias].index != index))   //'&' is bit operation symbol
        {   //second condition is used to avoid numbers[index] to be the (target - numbers[index])
            ret[0] = index + 1;
            ret[1] = hashTable[bias].index + 1;
            hashTableFree(hashTable, primeNumber);
            return ret;
        }else   //keep going to find the next node
        {
            plistNode tail = hashTable[bias].next;
            while (NULL != tail)
            {
                if (numbers[tail->index] == (target - numbers[index]))
                {
                    ret[0] = index + 1;
                    ret[1] = tail->index + 1;
                    hashTableFree(hashTable, primeNumber);
                    return ret;
                }else
                {
                    tail = tail->next;
                }
            }
        }
    }
    hashTableFree(hashTable, primeNumber);
    return NULL;
}
int main(int argc, char **argv)
{
    //int array[] = {438,507,629,255,813,423,536,428,340,767,208,808,882,142,835,423,331,545,627,750,397,675,662,92,465,627,15,522,395,727,561,73,570,606,826,651,743,214,881,685,820,326,653,334,698,604,938,260,51,597,291,855,427,117,943,142,166,439,833,4,180,10,531,350,785,989,607,303,554,764,769,451,654,752,15,90,505,159,1,516,801,938,442,543,761,548,523,766,445,696,217,352,333,383,868,764,556,943,280,140,627,870,635,753,743,978,611,326,405,143,564,256,304,913,570,331,340,222,952,959,535,113,148,125,874,354,984,753,423,448,235,621,796,355,64,682,326,500,609,293,566,974,808,568,729,173,735,764,987,588,227,961,621,340,245,570,640,814,635,482,520,563,695,399,95,92,813,135,342,513,410,943,64,458,801,835,977,932,838,604,500,266,395,108,788,161,769,662,697,167,143,383,880,19,758,552,396,226,548,560,916,766,568,192,100,734,639,288,187,465,345,535,293,130,488,172,108,313,800,662,644,758,843,953,73,543,630,37,711,372,372,410,60,973,750,833,827,572,31,157,473,529,410,650,930,635,253,203,159,431,848,969,982,229,504,617,273,723,854,572,879,382,18,418,990,321,871,544,662,900,340,358,788,998,376,87,520,543,717,67,713,419,108,796,143,342,896,526,926,362,23,63,426,514,526,499,857,87,499,635,496,69,558,635,1,635,125,611,459,11,14,305,969,225,677,354,90,509,317,895,617,798,210,830,63,488,139,500,744,564,295,782,214,569,863,835,14,70,687,321,130,933,822,761,985,637,995,604,932,54,51,170,951,774,117,117,863,940,599,820,473,350,572,776,198,958,1,281,539,874,38,205,591,901,588,743,926,270,675,135,208,588,438,444,752,172,709,191,199,494,743,854,362,340,170,909,434,258,621,983,119,37,281,987,53,486,709,824,817,590,632,798,207,691,592,358,92,316,864,345,488,408,172,392,402,188,880,336,350,739,301,953,314,414,261,701,431,984,350,800,476,370,952,580,585,335,14,486,448,710,637,134,665,166,631,526,877,940,492,855,563,417,517,543,496,979,802,100,100,854,706,350,796,140,46,434,811,543,743,614,838,803,583,280,748,124,570,134,18,282,879,324,142,904,861,884,974,630,319,340,130,954,130,199,681,465,295,597,492,893,552,920,370,221,293,26,632,695,967,372,321,723,907,701,733,520,482,927,11,606,466,404,529,402,166,646,60,802,101,822,93,12,336,136,650,539,640,791,108,997,268,833,562,132,423,879,884,362,374,522,188,496,472,531,434,942,46,528,423,504,664,867,467,685,899,884,746,548,937,296,436,295,486,722,288,465,89,736,900,174,497,37,84,817,411,486,387,949,893,187,776,771,617,175,516,705,296,452,268,6,922,402,991,723,609,98,347,588,554,80,169,197,931,19,597,888,164,347,27,916,378,630,321,644,156,362,4,705,164,465,543,806,282,827,448,670,950,458,388,239,744,507,516,414,459,934,130,924,440,166,788,343,379,884,758,808,912,187,706,419,88,355,996,331,777,500,863,796,627,124,535,561,466,370,101,383,813,44};
    int array[] = {3,2,4};
    size_t n = sizeof(array)/sizeof(int);
    int target = 6;
    int* result = twoSum_hash(array, (int)n, target);
    if (NULL != result)
    {
        printf("The index1: %d; the index2: %d\n", result[0], result[1]);
        printf("values are %d and %d.", array[result[0]-1], array[result[1]-1]);
        free(result);//memory deallocation
    }else
    {
        printf("result is not available!\n");
    }
}