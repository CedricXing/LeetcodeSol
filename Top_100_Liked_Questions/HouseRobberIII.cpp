#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/* Sol 0
	* 从当前节点开始的最大值，max(root->val+四个孙子树求得的最大值，两个儿子树求得的最大值)，整个过程可以递归地进行。
	*/
    int rob(TreeNode* root) {
        int l,r;
        return helper(root,l,r);
    }
    
    int helper(TreeNode *root,int &l,int &r){
        if(root == nullptr) return 0;
        int ll = 0,lr = 0,rl = 0,rr = 0;
        l = helper(root->left,ll,lr);
        r = helper(root->right,rl,rr);
        return max(root->val + ll + lr + rl + rr,l + r);
    }
};