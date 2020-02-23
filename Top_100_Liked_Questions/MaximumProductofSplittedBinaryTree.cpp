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
    int maxProduct(TreeNode* root) {
        int sum_ = getSum(root);
        int maxP = 0;
        maxProduct(root,sum_,maxP);
        return maxP;
    }

    int maxProduct(TreeNode* root,int sum_,int &maxP){
        if(root == nullptr) return 0;
        int left_sum = maxProduct(root->left,sum_,maxP);
        int right_sum = maxProduct(root->right,sum_,maxP);
        maxP = max(maxP,max((sum_ - right_sum) * right_sum,(sum_ - left_sum) * left_sum));
        return root->val + left_sum + right_sum;
    }

    int getSum(TreeNode *root){
        if(root == nullptr) return 0;
        else return root->val + getSum(root->left) + getSum(root->right);
    }
};