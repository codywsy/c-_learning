/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Common {
public:
    vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
        // write code here
        vector<int> ret;
        if(headA == NULL || headB == NULL)
        	return ret;

        ListNode* A = headA;
        ListNode* B = headB;

        while(A!=NULL || B!=NULL)
        {
        	if(A->val == B->val)
        	{
        		ret.push_back(A->val);
        		A = A->next;
        		B = B->next;
        	}

        	A->val > B->val? B=B->next : A=A->next;
        }

        return ret;
    }
};