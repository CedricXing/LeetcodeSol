#include <stack>
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
    * For a current node,if its left node is not nullptr, 
    * we should tranfer its left subtree to its right subtree,and ofcourse,
    * befort its original subtree.
    * So, the key point is to find the correct node in left subtree to link the
    * current right subtree.
    * There are two great solutions:
    * 0 : Find the correct node to link the current right subtree directly.
    * 1 : Use a stack to store the right node.
    */

   /* Sol 0
    * The correct node is current node's left child's rightmost child. BUT WHY?
    * Reason : Actually, according to the preorder, the correct node should check
    * left child too. But indeed, if the rightmost child's left child is not null, it should
    * be processed in the same, so it does not need to do so.
    * The solution is easy to understand. And O(1) space.
   */
    void flatten(TreeNode* root) {
        TreeNode *current = root;
        while(current != nullptr){
            if(current->left != nullptr){
                TreeNode *pre = current->left;
                while(pre->right != nullptr){
                    pre = pre->right;
                }
                //now pre is the correct node to link the right subtree
                pre->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }
            current = current->right;
        }
    }

    /* Sol 1
    * Use a stack to store the right child.
    * So, the right child won't be processed until all the childs in left subtree
    * are visited.
    */
    void flatten1(TreeNode *root){
        if(!root)   return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *current = st.top();
            st.pop();
            if(current->right) st.push(current->right);
            if(current->left) st.push(current->left);
            if(!st.empty()){
                current->right = st.top();
            }
            current->left = nullptr;
        }
    }
};