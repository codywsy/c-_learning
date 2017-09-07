class TreeToString {
public:
    string toString(TreeNode* root) {
        // write code here
        return preOrder(root);
    }
    
    string preOrder(TreeNode* root){
    	string ret;
    	stack<TreeNode *> TreeStack;
    	TreeStack.push(root);
    	TreeNode *cur;

    	while(!TreeStack.empty()){
    		cur = TreeStack.top();
    		TreeStack.pop();
    		if(cur){
    			ret += getString(cur->val);
    		}
    		else if(!cur){
    			ret += "#!";
			}
			if(cur){
    			TreeStack.push(cur->right);
  				TreeStack.push(cur->left);
  			}
    	}

    	return ret;
    }   

    string getString(int val){
    	string str;
    	char ch[256];
    	sprintf_s(ch,"%d", val);
    	str = ch;
    	str += "!";
    	return str;
    }
    
};