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
    int findLongest(TreeNode* root) {
        // write code here
		if(!root)
			return 0;
		int lh=0, rh=0;
		int lmax=0, rmax=0;

		if(root->left)
			lh = height(root->left,lmax);
		if(root->right)
			rh = height(root->right,rmax);

		return max(max(lmax,rmax), lh+rh+1);
    }

	int height(TreeNode *root, int &maxDis){
		int lh=0, rh=0;
		
		if(root->left)
			lh = height(root->left,maxDis);
		if(root->right)
			rh = height(root->right,maxDis);

		if(rh+lh+1 > maxDis) maxDis = lh+rh+1;

		return max(lh,rh)+1;
	}
};
