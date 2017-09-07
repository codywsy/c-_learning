class Divide {
public:
    ListNode* listDivide(ListNode* head, int val) {
        // write code here
        if(head == NULL || head->next==NULL)
        	return head;
        else
        {
        	ListNode* nxt = NULL;
        	ListNode* sH = NULL;
        	ListNode* sT = NULL;
        	ListNode* bH = NULL;
        	ListNode* bT = NULL;
        	while(head!=NULL)
        	{
        		nxt = head->next;
        		head->next = NULL;
        		if(head->val <= val)
        		{
        			if(sH)
        			{
        				sT->next = head;
        				sT = head;
        			} else
        			{
        				sH = head;
        				sT = head;
        			}
        		} else
        		{
        			if(bH)
        			{
        				bT->next = head;
        				bT = head;
        			} else
					{
						bH = head;
						bT = head;
					}        		
        		}
        		head = nxt;
        	}

        	if(sT != NULL)
       			sT->next = bH;
        	
        	return sH!=NULL? sH:bH;
        }
    }
};