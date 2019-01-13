#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    /* Sol
    * Using a map to store the depth of the node.
    * High space complexity.
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)   return result;
        queue<TreeNode*> q;
        unordered_map<TreeNode*,int> map;
        q.push(root);
        map[root] = 0;
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(result.size() <= map[node]){
                vector<int> vec;
                vec.push_back(node->val);
                result.push_back(vec);
            }
            else result[map[node]].push_back(node->val);
            if(node->left != nullptr) {
                q.push(node->left);
                map[node->left] = map[node] + 1;
            }
            if(node->right != nullptr) {
                q.push(node->right);
                map[node->right] = map[node] + 1;
            }
        }
        return result;
    }

    /* Sol 1
    * Using nullptr to indicate the end of a level.
    */
    vector<vector<int>> levelOrder1(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.emplace(root);q.emplace(nullptr);
        vector<vector<int>> result;
        vector<int> level;
        while(true){
            TreeNode *node = q.front();
            q.pop();
            if(node == nullptr){
                result.push_back(level);
                level.clear();
                if(q.empty())   return result;
                else q.emplace(nullptr);
                continue;
            }
            level.push_back(node->val);
            if(node->left) q.emplace(node->left);
            if(node->right) q.emplace(node->right);
        }
    }
};
