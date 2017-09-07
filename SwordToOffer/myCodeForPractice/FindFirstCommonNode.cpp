ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	//get the length of two linked list
	unsigned int nLength1 = GetListLength(pHead1);
	unsinged int nLength2 = GetListLength(pHead2);

	int LengthDiff = nLength1 - nLength2;
	ListNode* ListLong = pHead1;
	ListNode* ListShort = pHead2;

	if(nLength<nLength2)
	{
		LengthDiff = nLenght2 - nLength1;
		ListLong = pHead2;
		ListShort = pHead1;
	}

	//Beforhead, moving LengthDiff steps
	for(int i = 0; i<length; ++i)
		ListLong = ListLong->m_pNext;

	while( (ListLong!=NULL) && (ListShort!=NULL) && (ListLong!=ListShort))
	{
		ListLong = ListLong->m_pNext;
		ListShort = ListShort->m_pNext;
	}

	if(ListLong!=NULL)
		return ListLong;
}

unsigned int GetListLength(ListNode *pHead)
{
	unsigned int nLength = 0;
	ListNode* pNode = pHead;
	while(pNode!=NULL)
	{
		++nLength;
		pNode = pNode->m_pNext;
	}

	return nLength;
}