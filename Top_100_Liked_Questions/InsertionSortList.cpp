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
	* Insertion Sort using a dummy node.
	*/
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1),*current = head;
        while(current!=nullptr){
            ListNode *p = &dummy;
            for(;p->next != nullptr && p->next->val < current->val;p=p->next) ;
            ListNode *temp = current->next;
            current->next = p->next;
            p->next = current;
            current = temp;
        }
        return dummy.next;
    }
};
