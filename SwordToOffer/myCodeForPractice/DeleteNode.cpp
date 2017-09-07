struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDelete)
{
	if(!pListHead || !pToBeDelete)
		return;

	//要删除的不是尾结点
	if(pToBeDelete->m_pNext!=NULL)
	{
		ListNode* pNext pToBeDelete->m_pNext;
		pToBeDelete->m_nValue = pNext->m_nValue;
		pToBeDelete->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = NULL;
	}
	//链表只有一个结点，删除头结点（也是尾结点）
	else if(*pListHead == pToBeDelete)
	{
		delete pToBeDelete;
		pToBeDelete = NULL;
		*pListHead = NULL;
	}
	//链表不止一个结点，删除尾结点
	else 
	{
		ListNode* pNext = *pListHead;

		while(pNext->m_pNext != pToBeDelete)
		{
			pNext = pNext->m_pNext;
		}

		delete pToBeDelete;
		pToBeDelete = NULL;
		pNext->m_pNext = NULL;
	}
}