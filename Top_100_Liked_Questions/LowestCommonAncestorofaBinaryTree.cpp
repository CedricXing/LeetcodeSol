#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
	/* Sol 0
	* If the left subtree and right subtree of the current (sub)tree both contains the objective nodes,
    * then the result is the current node. Otherwise, if only one subtree contains the objective nodes,
    * then the result is the related subtree root node.
	*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        return (left==nullptr) ? right : (right == nullptr) ? left : root;
    }
};