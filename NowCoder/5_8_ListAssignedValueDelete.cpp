/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ClearValue {
public:
    ListNode* clear(ListNode* head, int val) {
        // write code here
    	while(head!=NULL)
    	{
    		if(head->val != val) {
    			break;
    		}
    		head = head->next;
    	}

  		ListNode* pHead = NULL;
  		ListNode* pTail = NULL;
  		while(head!=NULL)
  		{
			if(head->val != val)
			{
				if(pHead == NULL)
				{
					pHead = new ListNode(head->val);
					pTail = pHead;
				}
				else
				{
					pTail->next = new ListNode(head->val);
					pTail = pTail->next;
				}
			}
			else
			{
				head = head->next;
			}
  		}

  		pTail->next = NULL;
  		return head;
    }

};