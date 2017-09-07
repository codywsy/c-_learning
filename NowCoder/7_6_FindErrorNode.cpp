class FindErrorNode {
public:
    vector<int> findError(TreeNode* root) {
        // write code here
        vector<int> ret;
        if(!root)
            return ret;
        //inorder
        vector<int> ivec;
        inOrder(root, ivec);
        //processing
        processing(ret,ivec);
        return ret;
    }
     
    void inOrder(TreeNode *root, vector<int> &vec){
        if(!root)
            return;
 
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }
     
    void processing(vector<int> &err, vector<int> vec){
        vector<int>::iterator iter = vec.begin();
        int lastvalue = *iter;
        iter++;
        int flag = 0;
        int value1;
        int value2;
        while(iter!=vec.end()){
            if(lastvalue > *iter)
                if(flag == 0){ 
                    value1 = *iter;
                    value2 = lastvalue;
                    flag = 1;
                }
                else if(flag==1){
                    value1 = *iter;
                    break;
                }  
            lastvalue = *iter;
            ++iter;
        }
        err.push_back(value1);
        err.push_back(value2);
    }
};