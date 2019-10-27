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
	* Use recursion
	*/
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)    return head;
        ListNode *temp = head;
        head = temp->next;
        temp->next = swapPairs(head->next);
        head->next = temp;
        return head;
    }
};