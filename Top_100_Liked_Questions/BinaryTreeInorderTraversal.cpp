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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode *p = root;
        while(!st.empty() || p != nullptr){
            while(p != nullptr){
                st.push(p);
                p = p->left;
            }
            if(!st.empty()){
                TreeNode *tmp = st.top();
                st.pop();
                result.push_back(tmp->val);
                p = tmp->right;
            }
        }
        return result;
    }
};