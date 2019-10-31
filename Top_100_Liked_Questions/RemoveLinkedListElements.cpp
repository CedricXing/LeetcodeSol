#include <vector>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1),*p = &dummy;
        dummy.next = head;
        while(p->next != nullptr){
            if(p->next->val == val) p->next = p->next->next;
            else p = p->next;
        }
        return dummy.next;
    }
};