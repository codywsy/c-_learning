/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
//循环链表版本
class InsertValue {
public:
    ListNode* insert(vector<int> A, vector<int> nxt, int val) {
        // write code here
        if(A.empty())
        {
        	ListNode* pHead = new ListNode(val);
        	pHead->next = pHead;
        	return pHead;
        }
        else
        {
        	//construction the link
        	ListNode* pHead = new ListNode(A[0]);
 			ListNode* pNode = pHead;

        	vector<int>::iterator iter = A.begin();
        	iter++;
        	while(iter != A.end())
        	{
        		ListNode* pCur = new ListNode(*iter);
        		pNode->next = pCur;
       			pNode = pNode->next;
       			iter++;
        	}
        	pNode->next = pHead;

        	//start to insert
        	ListNode* pre = pHead;
        	ListNode* cur = pre->next;
        	ListNode* tar = new ListNode(val); 
        	while(cur != pHead)
        	{
        		if(pre->val <= val && val <= cur->val)
        		{
        			tar->next = cur;
        			pre->next = tar;
        			return pHead;
        		}

        		cur = cur->next;
        		pre = pre->next;
        	}

        	tar->next = cur;
        	pre->next = tar;

        	if(pre->val > val)
        		pHead = tar;

        	return pHead;
        }

    }
};



//单向链表版本
class InsertValue {
public:
    ListNode* insert(vector<int> A, vector<int> nxt, int val) {
        // write code here
        if(A.empty())
        {
        	ListNode* pHead = new ListNode(val);
        	return pHead;
        }
        else
        {
        	//construction the link
        	ListNode* pHead = new ListNode(A[0]);
 			ListNode* pNode = pHead;

        	vector<int>::iterator iter = A.begin();
        	iter++;
        	while(iter != A.end())
        	{
        		ListNode* pCur = new ListNode(*iter);
        		pNode->next = pCur;
       			pNode = pNode->next;
       			iter++;
        	}

        	//start to insert
        	ListNode* pre = pHead;
        	ListNode* cur = pre->next;
        	ListNode* tar = new ListNode(val); 

        	if(pHead->val > val)
        	{
        		tar->next = pHead;
        		return tar;
        	}

        	while(cur != NULL)
        	{
        		if(pre->val <= val && val <= cur->val)
        		{
        			tar->next = cur;
        			pre->next = tar;
        			return pHead;
        		}

        		cur = cur->next;
        		pre = pre->next;
        	}

        	tar->next = cur;
        	pre->next = tar;
        	return pHead;
        }

    }
};