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
	* In-order to find the kth smallest node.
    * It's worth noting that we just visit every node only once. So it's O(n) in the worst case.
    * Actually, it's a bottom-up search. But if we write a function count() to count the child nodes, it may
    * visit each node more than once.
	*/
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        kthSmallest(root,k,result);
        return result;
    }
    
private:
    int kthSmallest(TreeNode *root,int k,int &result){
        if(root == nullptr) return 0;
        int left_num = kthSmallest(root->left,k,result);
        int right_num = kthSmallest(root->right,k - left_num - 1,result);
        if(k == left_num + 1) result = root->val;
        return left_num + right_num + 1;
    }
};