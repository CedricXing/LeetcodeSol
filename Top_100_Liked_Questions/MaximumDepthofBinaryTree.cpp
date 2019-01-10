#include <math.h>
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
    /* Sol 0
    * It's easy to solve this problem recursively.
    */
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        else return 1 + fmax(maxDepth(root->left),maxDepth(root->right));
    }

    /* Sol 1
    * I also give the iterative solution below.
    * Firstly, we need a queue to iteratively traverse the tree.
    * Secondly, we need a map to store the depth of each node.
    */
    int maxDepthIteratively(TreeNode *root){
        if(root == NULL)
            return 0;
        queue<TreeNode*> q;
        unordered_map<TreeNode*,int> map;
        q.push(root);
        map[root] = 1;
        int maxDepth = 1;
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(node->left != NULL){
                q.push(node->left);
                map[node->left] = map[node] + 1;
                if(map[node->left] > maxDepth)
                    maxDepth = map[node->left];
            }
            if(node->right != NULL){
                q.push(node->right);
                map[node->right] = map[node] + 1;
                if(map[node->right] > maxDepth)
                    maxDepth = map[node->right];
            }
        }
        return maxDepth;
    }
};