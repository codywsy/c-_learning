class TreeToSequence {
public:
    vector<vector<int> > convert(TreeNode* root) {
        // write code here
        vector<vector<int> > ret;
        vector<int> OrderVec;
        //preOrder
        preOrder(root, OrderVec);
        ret.push_back(OrderVec);
        //inorder
		OrderVec.clear();        
        inOrder(root, OrderVec);
        ret.push_back(OrderVec);
        //postorder
 		OrderVec.clear();        
        postOrder(root, OrderVec);
        ret.push_back(OrderVec);

        return ret;               
    }
    
    void preOrder(TreeNode *root, vector<int> vec) {
        if(!root)
        	return;

        vec.push_back(root->val);
        preOrder(root->left, vec);
        preOrder(root->right, vec);
    }

    void inOrder(TreeNode *root, vector<int> vec) {
        if(!root)
        	return;

        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }

    void postOrder(TreeNode *root, vector<int> vec) {
        if(!root)
        	return;

        postOrder(root->left, vec);
        postOrder(root->right, vec);
        vec.push_back(root->val);

    }    
};
