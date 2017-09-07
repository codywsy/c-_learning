class FoldPaper {
public:
    vector<string> foldPaper(int n) {
        // write code here
		vector<string> result;
		if(!n)
			return result;
		
		TreeNode *root = new TreeNode(1);
		constructTree(n, root); 
		getresult(root, result);
		return result;

    }

	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x): val(x), left(NULL), right(NULL) {}
	};

	void constructTree(int n, TreeNode *root){
		if(n>1){
			root->left = new TreeNode(2);
			root->right = new TreeNode(1);
			n--;
			constructTree(n, root->left);
			constructTree(n, root->right);
		}
	}

	void getresult(TreeNode *root, vector<string> &str){
		if(!root)
			return;

		getresult(root->right, str);
		if(root->val == 1)
			str.push_back("down");
		else if(root->val == 2)
			str.push_back("up");
		getresult(root->left, str);
	}

};

