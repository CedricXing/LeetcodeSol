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
    * Use an index rootPos to indicate the current root in preorder -- O(1) space.
    * Recursively, build the left subtree before the right subtree and 
    * increase rootPos by one every time building a tree. So the order of root node will be correct.
    */
    int root_pos;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)    return nullptr;
        root_pos = 0;
        return buildTree(preorder,inorder,0,inorder.size() - 1);
    }

    /* Annotations
    * left indicates the left-most node of a subtree in inorder
    * right indicates the right-most node of a subtree in inorder 
    */
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder,int left,int right){
        TreeNode *node = new TreeNode(preorder[root_pos]);
        int pivot = left;
        for(;pivot <= right;++pivot){
            if(inorder[pivot] == preorder[root_pos])
                break;
        }
        ++root_pos;
        if(left == right)   return node;

        //Attention: build the left subtree first.
        if(left < pivot) node->left = buildTree(preorder,inorder,left,pivot-1);
        if(pivot < right) node->right = buildTree(preorder,inorder,pivot+1,right);
        return node;
    }

    /* Sol 1
	* Using cache, for example, a map to speed up when searching for the position of current root.
	*/
};