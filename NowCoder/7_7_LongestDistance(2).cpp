/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
 
class LongestDistance {
public:
    void get(TreeNode *rt,int *mx,int &ret){
        int lmx = 0,rmx = 0;
        if(rt->left){
            get(rt->left,mx,ret); lmx = mx[rt->left->val];
        }
        if(rt->right){
            get(rt->right,mx,ret); rmx = mx[rt->right->val];
        }
        mx[rt->val] = max(lmx,rmx) + 1;
        if(lmx + rmx + 1 > ret) ret = lmx + rmx + 1;
    }
    int findLongest(TreeNode* root) {
        int ret = 0;
        int mx[550];
        get(root,mx,ret);
        return ret;
    }
};