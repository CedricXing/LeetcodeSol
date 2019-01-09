#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    /* Analysis
     * The key point of this problem is that two nodes (① is left child and ② is right child) in symmetric positions 
     * must have the same value and the left child of ① should be compared to the right child of ② and 
     * the right child of ① should be compared to the left child of ②.
    */

    /* Sol 0
     * Compare recursively.
     * Easy to pass.
    */
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        else    return isSymmetric(root->left,root->right);
    }

    bool isSymmetric(TreeNode *left,TreeNode *right){
        if(left == NULL && right == NULL)
            return true;
        if(left == NULL or right == NULL)
            return false;
        return (left->val == right->val) && isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
    }

    /* Sol 1
     * Compare iteratively using queue.
    */
    bool isSymmetric2(TreeNode *root){
        queue<TreeNode*> p,q;
        if(root == NULL)
            return true;
        p.push(root->left);
        q.push(root->right);
        while(!p.empty() && !q.empty()){
            TreeNode *left = p.front();
            TreeNode *right = q.front();
            p.pop();
            q.pop();
            if(left == NULL && right == NULL)
                continue;
            else if(left == NULL or right == NULL)
                return false;
            else{
                if(left->val != right->val)
                    return false;
                p.push(left->left);p.push(left->right);
                q.push(right->right);q.push(right->left);
            }
        }
        return true;
    }
};