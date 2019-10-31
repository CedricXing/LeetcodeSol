#include <vector>
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
	* In order to build a balanced binary tree, we should choose the 
    * middle element of the array as the root. Do it recursively.
	*/
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;    
        return sortedArrayToBST(nums,0,nums.size()-1);
    }

    TreeNode* sortedArrayToBST(vector<int> &nums,int left,int right){
        if(left == right){
            return new TreeNode(nums[left]);
        }
        int middle = left + (right - left) / 2;
        TreeNode *node = new TreeNode(nums[middle]);
        if(middle > left) node->left = sortedArrayToBST(nums,left,middle - 1);
        if(middle < right) node->right = sortedArrayToBST(nums,middle + 1,right);
        return node;
    }
};