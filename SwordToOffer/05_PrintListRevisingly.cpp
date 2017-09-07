#include <iostream>

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};


void PrintListRevisingly_Iteratively(ListNode* pHead)
{
	//初始化一个堆栈存链表节点
	std::stack<ListNode*> nodes;

	//压入堆栈
	ListNode* pNode = pHead;
	while(pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	//推出堆栈
	while(!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
}

void PrintListRevisingly_Recursively(ListNode* pHead)
{
	if(pHead != NULL)
	{
		if(pHead -> m_pNext != NULL)
		{
			PrintListRevisingly_Recursively(pHead->m_pNext);
		}

		printf("%d\t", pHead -> m_nValue);
	}

}
