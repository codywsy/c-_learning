class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       // if(preorder.empty())
       //    return nullptr;

        TreeNode* rt = CreateTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
        return rt;
    } 
    
    TreeNode* CreateTree(vector<int>& preorder, vector<int>& inorder, int startPre,int endPre, int startIn,int endIn)
    {
        //1)递归必须要有停止条件
        if(startPre>endPre )
            return nullptr;
        int value = preorder[startPre];
        if(startPre==endPre)
            return TreeNode* root = new TreeNode(value);
        //2)递归公式
        
        int i = startIn;
        for(;i<endIn;++i)
        {
            if(inorder[i] == value)
                break;
        }
        TreeNode* root = new TreeNode(value);
        //root->value = value;
        root->left  = CreateTree(preorder,inorder,startPre+1,startPre+i-startIn,startIn,i-1);
        root->right = CreateTree(preorder,inorder,startPre+i-startIn+1,endPre,i+1,endIn);
        
        return root;
        
    }
};
