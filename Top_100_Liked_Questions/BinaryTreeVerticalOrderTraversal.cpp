#include <vector>
#include <queue>
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
	* 有点繁琐了，但是直接算出了列数。也可以不算列数，用一个map先存。
	*/
    int left_most,right_most;
    vector<vector<int> > verticalOrder(TreeNode* root) {
        if(root == nullptr) return vector<vector<int> >();
        left_most = right_most = 0;
        get_deep(root,0);
        vector<vector<int> > result(left_most + right_most + 1,vector<int>());
        queue<pair<TreeNode*,int> > q;
        q.push(make_pair(root,left_most));
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int pos = p.second;
            result[pos].push_back(p.first->val);
            if(p.first->left != nullptr) q.push(make_pair(p.first->left,pos - 1));
            if(p.first->right != nullptr) q.push(make_pair(p.first->right,pos + 1));
        }
        return result;
    }
    
    void get_deep(TreeNode *root,int pos){
        if(root == nullptr) return;
        if(pos < 0) left_most = max(left_most,abs(pos));
        if(pos > 0) right_most = max(right_most,abs(pos));
        if(root->left != nullptr) get_deep(root->left,pos - 1);
        if(root->right != nullptr) get_deep(root->right,pos + 1);
    }
};