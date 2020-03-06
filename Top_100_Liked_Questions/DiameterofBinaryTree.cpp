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
	* 类似LeetCode 124求最大路径和的思路，后序遍历，一遍扫描即可。
    * 核心在于每次返回的时候，只能返回单边的长；而双边的长都已经用来更新过max_len了。
	*/
    int diameterOfBinaryTree(TreeNode* root) {
        int max_len = 0;
        helper(root,max_len);
        return max_len == 0 ? 0 : max_len - 1;
    }
    
    int helper(TreeNode *root,int &max_len){
        if(root == nullptr) return 0;
        int left = helper(root->left,max_len);
        int right = helper(root->right,max_len);
        
        int current_len = 1 + left + right;
        max_len = max(current_len,max_len);
        if(left != 0 && right != 0) return 1 + max(left,right);
        else return current_len;
    }
};