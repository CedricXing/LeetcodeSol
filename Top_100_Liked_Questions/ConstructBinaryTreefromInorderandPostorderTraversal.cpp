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
    int root_pos;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()==0) return nullptr;
        root_pos = postorder.size() - 1;
        return buildTree(inorder,postorder,0,inorder.size()-1);        
    }

    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder,int left, int right){
        int pivot = left;
        for(;pivot <=right;++pivot){
            if(inorder[pivot] == postorder[root_pos])
                break;
        }
        TreeNode *node = new TreeNode(postorder[root_pos]);
        --root_pos;
        if(left == right)   return node;
        if(right > pivot) node->right = buildTree(inorder,postorder,pivot+1,right);
        if(left < pivot) node->left = buildTree(inorder,postorder,left,pivot-1);
        return node;
    }
};