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
	* Just use the reverse template.
	*/
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1),*p = &dummy;
        dummy.next = head;
        for(int i = 1;i < m;++i) p = p->next;
        ListNode *first = p->next,*pre = nullptr;
        for(int i = m;i <= n;++i){
            ListNode *temp = first->next;
            first->next = pre;
            pre = first;
            first = temp;
        }
        p->next->next = first;
        p->next = pre;
        return dummy.next;
    }
};