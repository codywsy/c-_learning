/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class MaxSubtree {
public:
    TreeNode* getMax(TreeNode* root) {
        // write code here
		int max, min, num;
		TreeNode* ret = get(root, max, min, num);
		return ret;
    }

	TreeNode* get(TreeNode* root, int& max, int& min, int &num){
		if(!root)
			return root;
		int lnum=0, rnum=0;
		int lmax = root->val;
		int rmax = root->val;
		int lmin = root->val;
		int rmin = root->val;

		TreeNode* left = get(root->left, lmax, lmin, lnum);
		TreeNode* right =get(root->right, rmax, rmin, rnum);

		if( left==root->left && right==root->right && lmax<= root->val && root->val<=rmin){
			num = lnum+rnum+1;
			max = rmax;
			min = lmin;
			return root;
		}
		else if( lnum>rnum || (lnum==rnum && lmax>rmax) ){
			num = lnum;
			max = lmax;
			min = lmin;
			return left;
		}
		else if( lnum<rnum || (lnum==rnum && lmax<rmax) ){
			num = rnum;
			max = rmax;
			min = rmin;
			return right;
		}
		return root;
	}
};
