/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class CheckBalance {
public:
    bool check(TreeNode* root) {
        // write code here
        if(!root)
        	return true;

        return abs(getHeight(root->left)-getHeight(root->right)) < 2 && check(root->left) && check(root->right);
    }

    int getHeight(TreeNode* root){
    	if(!root)
    		return 0;

    	return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    
};