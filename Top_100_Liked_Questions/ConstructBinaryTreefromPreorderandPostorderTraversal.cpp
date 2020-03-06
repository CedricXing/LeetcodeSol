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
    int root;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.empty()) return nullptr;
        root = 0;
        return helper(pre,post,0,post.size() - 1);
    }
    
    TreeNode *helper(vector<int> &pre,vector<int> &post,int left,int right){
        TreeNode *node = new TreeNode(pre[root++]);
        if(left >= right) return node;
        int pivot = left;
        for(;pivot < right;++pivot) // right is the current root
            if(post[pivot] == pre[root]) break;
        if(left <= pivot) node->left = helper(pre,post,left,pivot);
        if(pivot + 1 < right) node->right = helper(pre,post,pivot + 1,right - 1);
        return node;
    }
};

	/* Sol 1
	* More concise solution.
	*/
class Solution1 {
public:
    int preIndex = 0, posIndex = 0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    	TreeNode* root = new TreeNode(pre[preIndex++]);
    	if (root->val != post[posIndex])
    		root->left = constructFromPrePost(pre, post);
    	if (root->val != post[posIndex])
    		root->right = constructFromPrePost(pre, post);
    	posIndex++;
    	return root;
    }
};
