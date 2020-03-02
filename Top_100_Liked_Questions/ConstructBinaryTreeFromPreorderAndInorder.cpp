#include <vector>
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
    * Iterative solution.
    * 对于当前的根，如果对应的inorder中的值不等于它，说明都还是这个根的坐半子树，则先处理左子树；等到相等了，则再处理右子树。
	*/
    TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;
        stack<TreeNode*> st;
        int pre_inx = 0,in_inx = 0;
        TreeNode *result = new TreeNode(preorder[pre_inx]);
        st.push(result);
        while(!st.empty()){
            TreeNode *root = st.top();
            if(root->val == inorder[in_inx]){ // 当前这个根的左半部分都已经处理完毕
                st.pop();
                ++in_inx;
                if(in_inx == inorder.size()) break;
                if(!st.empty() && st.top()->val == inorder[in_inx]) continue;
                root->right = new TreeNode(preorder[++pre_inx]);
                st.push(root->right);
            }
            else{ // 开始处理这个根的左半部分
                root->left = new TreeNode(preorder[++pre_inx]);
                st.push(root->left);
            }
        }
        return result;
    }
};