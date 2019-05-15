#include <iostream>
#include <stack>
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
	* The key point is that one should not only compare a node to its leftnode or rightnode.
    * We must ensure a node has the maximum value in all its left tree and has the minimum value in all its right tree.
    * We can store the current [min,max]. BUT it's buggy to initialize min with INT_MIN or initialize max with INT_MAX
    * We solve it use in-order traversal.
    * Iterative way using a stack
	*/
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *pre = nullptr;
        while(root!=nullptr || !st.empty()){
            while(root!=nullptr){
                st.push(root);
                root=root->left;
            }
            root = st.top();
            st.pop();
            if(pre != nullptr && pre->val >= root->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }

	/* Sol 1
	* Recursive in-order traversal.
	*/
    bool isValidBST1(TreeNode *root){
        TreeNode *pre = nullptr;
        return isValid(root,pre);
    }

    bool isValid(TreeNode *node,TreeNode *&pre){//Attention: pre is reference here
        if(node==nullptr)   return true;
        if(!isValid(node->left,pre))    return false;
        if(pre != nullptr && pre->val >= node->val) return false;
        pre = node;
        return isValid(node->right,pre);
    }
};