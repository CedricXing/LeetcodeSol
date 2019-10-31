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
	* Every time move the odd node to the front.
	*/
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *left_tail = head,*current = head->next;
        while(current!= nullptr && current->next != nullptr){
            ListNode *temp1 = current->next->next,*temp2 = left_tail->next;
            left_tail->next = current->next;
            left_tail = current->next;
            current->next->next = temp2;
            current->next = temp1;
            current = temp1;
        }
        return head;  
    }

    /* Sol 1
	* split them into two lists and merge them at last
	*/
    ListNode* oddEvenList1(ListNode* head){
        if(head == nullptr) return head;
        ListNode *odd = head,*even = head->next,*even_head = even;
        while(even != nullptr && even->next != nullptr){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};
