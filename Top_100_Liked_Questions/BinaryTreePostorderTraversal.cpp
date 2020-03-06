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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *pre = nullptr, *p = root;
        vector<int> result;
        while(!st.empty() || p != nullptr){
            while(p != nullptr){
                st.push(p);
                p = p->left;
            }
            if(!st.empty()){
                TreeNode *tmp = st.top();
                if((tmp->left == nullptr && tmp->right == nullptr) || (tmp->right == nullptr && pre == tmp->left) || (tmp->right != nullptr && pre == tmp->right)){
                    result.push_back(tmp->val);
                    st.pop();
                    pre = tmp;
                }
                else {
                    p = tmp->right;
                }
            }
        }
        return result;
    }
};