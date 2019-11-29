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
	* DP solution. O(n^4) time complexity.
    * for n, choose i (1<=i<=n) as the root respectively.
	*/
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        vector<vector<TreeNode*>> dp(n+1);
        dp[0].push_back(nullptr);
        if(n == 0) return result;
        dp[1].push_back(new TreeNode(1));
        for(int i = 2;i <= n;++i){
            for(int j = 1;j <= i;++j){
                for(int k1 = 0;k1 < dp[j-1].size();++k1){
                    for(int k2 = 0;k2 < dp[i-j].size();++k2){
                        TreeNode *temp = new TreeNode(j);
                        temp->left = dp[j-1][k1];
                        temp->right = addValue(dp[i-j][k2],i-j);
                        dp[i].push_back(temp);
                    }
                }
            }
        }
        return dp[n];
    }

    TreeNode* addValue(TreeNode *root,int val){
        if(root == nullptr) return nullptr;
        TreeNode *newRoot = new TreeNode(root->val + val);
        newRoot->left = addValue(root->left,val);
        newRoot->right = addValue(root->right,val);
        return newRoot;
    }
};