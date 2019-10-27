#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/* Sol 0
	* In the kind of 'remove nodes' problems, we assume that there is no
    * memory leak if we don't use new keyword in our solution.
	*/
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head;
        while(current != nullptr){
            if(current->next != nullptr && current->val == current->next->val)
                current->next = current->next->next;
            else current = current->next;
        }
        return head;
    }
};