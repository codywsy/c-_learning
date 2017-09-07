/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) {
        // write code here
        if( k<2)
        	return head;

        ListNode* cur = head;
        ListNode* start = NULL;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        int count = 1;
        while(cur != NULL)
        {
        	next = cur->next;
        	if(count == k)
        	{
        		//区分一开始转换时候的情况的情况
        		start =(pre==NULL? head:pre->next);
        		head = (pre==NULL? cur:head);
        		resign(pre, start, cur, next);
        		pre = start;
        		count = 0;
        	}
        	count++;
        	cur = next;
        }

        return head;
    }

    void resign(ListNode* left, ListNode* start, ListNode* end, ListNode* right)
    {
    	ListNode* pre = start;
    	ListNode* cur = start->next;
    	ListNode* next = NULL;
    	while(cur != right)
    	{
    		next = cur->next;
    		cur->next = pre;
    		pre = cur;
    		cur = next;
    	}

    	if(left!=NULL)
    		left->next = end;

    	start->next = right;
    }

};