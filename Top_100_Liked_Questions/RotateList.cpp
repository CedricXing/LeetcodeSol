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
	* Just compute the position of new head.
	*/
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        int len = 1;
        ListNode *p = head;
        for(;p->next != nullptr;++len,p=p->next);
        if(k % len == 0) return head;
        ListNode *tail = p,*temp = head;
        int pos = len - k % len;
        p = head;
        for(int i = 0;i < pos - 1;++i)
            p = p->next;
        head = p->next;
        p->next = nullptr;
        tail->next = temp;
        return head;
    }
	/* Sol 1
	* After the first loop, it's very clever to make p->next = head. 
	*/
    ListNode* rotateRight1(ListNode* head, int k) {
        if(head == nullptr) return head;
        int len = 1;
        ListNode *p = head;
        for(;p->next != nullptr;++len,p=p->next);
        if(k % len == 0) return head;
        p->next = head;
        int pos = len - k % len;
        for(int i = 0;i < pos - 1;++i)
            p = p->next;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};