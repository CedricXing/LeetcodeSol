#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/* Sol 0
	* Just like a sorted array, we find the middle node of the list as the root node.
    * Time complexity raise to O(nlogn) 
    * Does anybody have better solutions?  
	*/
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        return sortedListToBST(head,nullptr); 
    }

    // the tail here is not the same as my solution of the sorted array one, the tail is not valid.
    TreeNode* sortedListToBST(ListNode *head,ListNode *tail){
        if(head->next == tail)  return new TreeNode(head->val);
        ListNode *slow = head,*fast = head;
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *node = new TreeNode(slow->val);
        if(slow != head) node->left = sortedListToBST(head,slow);
        if(slow->next != tail) node->right = sortedListToBST(slow->next,tail);
        return node;
    }
};