#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	/* Sol 0
	* Solve the problem recursively and use a global variable 'max_sum' to store the maximum sum.
    * For a tree, we first compute the max_sum of its left subtree and its right subtree, and compute the
    * current_sum involving the value of the root. Meanwhile, we update the 'max_sum'.
    * Finally, we need to return a max sum of the current tree, the path can only exist in the left subtree or the
    * right subtree, so we minus the minimum one if both are positive.
	*/
    int maxPathSum(TreeNode* root) {
        int max_sum = INT32_MIN;
        maxPathSum(root,max_sum);
        return max_sum;
    }
private:
    int maxPathSum(TreeNode *root,int &max_sum){
        if(root == nullptr) return 0;
        int left_sum = maxPathSum(root->left,max_sum);
        int right_sum = maxPathSum(root->right,max_sum);
        int current_sum = root->val;
        current_sum += (left_sum > 0) ? left_sum : 0;
        current_sum += (right_sum > 0) ? right_sum : 0;
        max_sum = max(max_sum,current_sum);
        
        if(left_sum > 0 && right_sum > 0)
            current_sum -= min(left_sum,right_sum);
        return current_sum;
    }
};