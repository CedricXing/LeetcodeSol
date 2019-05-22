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
	* Two recursive functions. The root of pathSum indicates the real root node.
    * To be honest, I didn't write the correct recursive functions at the first time,
    * though I know how to solve it. SO..., I think it should be a medium-difficulty problem.
    * hhh
	*/
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr)   return 0;
        return pathSum2(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
    }

    int pathSum2(TreeNode *root,int sum){
        if(root==nullptr) return 0;
        return (root->val==sum) + pathSum2(root->left,sum-root->val) + pathSum2(root->right,sum-root->val);
    }
};