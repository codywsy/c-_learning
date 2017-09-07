#include <stdio.h>
#include <stdlib.h>
#define functionPart

struct ListNode {
	int val;
	struct ListNode *next;
};

#ifdef functionPart
  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
#endif //functionPart

int main(void)
{
	//initialize two list
	struct ListNode* line1;
	struct ListNode* line2;
	struct ListNode* line3;
	struct ListNode* temp;
	struct ListNode* new;

	//line1
	line1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	temp = line1;
	temp->val=1;
	new = (struct ListNode*)malloc(sizeof(struct ListNode));
	temp->next = new;
	temp = temp->next;

	temp->val = 8;
	temp->next = NULL;
	
	//line2
	line2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	temp = line2;
	temp->val = 0;
	temp->next = NULL;


/*	while (line1 != NULL)
	{
		printf("%d\t", line1->val);
		line1 = line1->next;
	}
	printf("\n\n");

	while (line2 != NULL)
	{
		printf("%d\t", line2->val);
		line2 = line2->next;
	}
	printf("\n\n");

	getchar();*/

#ifdef functionPart
	//function
	line3=addTwoNumbers(line1,line2);

	while (line3 != NULL)
	{
		printf("%d\t", line3->val);
		line3 = line3->next;
	}
	printf("\n\n");

	getchar(); 

#endif //functionPart


	return 0;
}




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#ifdef functionPart
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
	struct ListNode* num1;
	struct ListNode* num2;
	struct ListNode* l3;
	struct ListNode* num3;
	struct ListNode *new;

	l3 = (struct ListNode*) malloc(sizeof(struct ListNode));
	num3 = l3;

	int carryBit = 0;
	int sum = 0;
	int temp1, temp2;

	num1 = l1;
	num2 = l2;
	temp1 = num1->val;
	temp2 = num2->val;
	while(num1||num2  )	//!((num1==NULL)&&(num2==NULL))
	{

		sum = temp1 + temp2 + carryBit;
		if (sum > 9)
		{
			carryBit = sum / 10;
			num3->val = sum % 10;

		}
		else
		{
			carryBit = 0;
			num3->val = sum;
		}

		//next decimal
		if (num1)
		{
			if (num1->next != NULL)
			{
				num1 = num1->next;
				temp1 = num1->val;
			}
			else
			{
				num1 = NULL;
				temp1 = 0;
			}
		}

		if (num2)
		{
			if (num2->next != NULL)
			{
				num2 = num2->next;
				temp2 = num2->val;
			}
			else
			{
				num2 = NULL;
				temp2 = 0;
			}
		}

		if (num1 || num2 || carryBit!=0)
		{
			new = (struct ListNode*) malloc(sizeof(struct ListNode));
			num3->next = new;
			num3 = num3->next;

			if (!(num1)||!(num2)||carryBit)
			{
				num3->val = carryBit;
			}
		}

	}

	num3->next=NULL;

	return l3;
    
}
#endif //functionPart