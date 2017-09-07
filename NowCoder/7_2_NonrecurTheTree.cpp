/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreeToSequence {
public:
    vector<vector<int> > convert(TreeNode* root) {
        // write code here
        vector<vector<int> > ret;

        //preorder
		ret.push_back(preOrder(root));       
        //inorder
        ret.push_back(inOrder(root));
        //postorder
        ret.push_back(postOrder(root));

        return ret;
    }

    vector<int> preOrder(TreeNode* root){
    	vector<int> ret;
    	stack<TreeNode *> TreeStack;
    	TreeStack.push(root);
    	TreeNode *cur;

    	while(!TreeStack.empty()){
    		cur = TreeStack.top();
    		TreeStack.pop();
    		ret.push_back(cur->val);
    		if(cur->right)
    			TreeStack.push(cur->right);
    		if(cur->left)
    			TreeStack.push(cur->left);
    	}

    	return ret;
    }

    vector<int> inOrder(TreeNode* root){
    	vector<int> ret;
    	stack<TreeNode *> TreeStack;
    	TreeNode *cur = root;
    	TreeNode *node;

    	while(!TreeStack.empty() || cur){
    		while(cur){
    			TreeStack.push(cur);
    			cur = cur->left;
    		}

    		node = TreeStack.top();
    		TreeStack.pop();
    		ret.push_back(node->val);
    		cur = node->right;
    	}

    	return ret;
    }

    vector<int> postOrder(TreeNode * root){
    	vector<int> ret;
    	stack<TreeNode *> s1;
    	stack<TreeNode *> s2;
    	TreeNode *cur;
    	s1.push(root);

    	while(!s1.empty()){
    		cur = s1.top();
    		s1.pop();
    		s2.push(cur);
    		if(cur->left)
    			s1.push(cur->left);
    		if(cur->right)
    			s1.push(cur->right);
    	}

    	while(!s2.empty()){
    		ret.push_back(s2.top()->val);
    		s2.pop();
    	}

    	return ret;
    }
};


