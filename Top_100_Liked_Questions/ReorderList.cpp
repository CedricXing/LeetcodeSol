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
	* O(1) space complexity, O(n) time complexity
    * I. find the middle node;
    * II. reverse the right half of the list;
    * III. insert the right half to the left part one by one.
	*/
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;
        ListNode *slow = head,*fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *middle = slow->next;
        slow->next = nullptr; // set the next of the last node of the left part to nullptr
        ListNode *p = middle,*pre = nullptr,*q = head;
        while(p != nullptr){
            ListNode *temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }
        while(pre != nullptr){
            ListNode *temp1 = q->next,*temp2 = pre->next;
            q->next = pre;
            pre->next = temp1;
            pre = temp2;
            q = temp1;
        }
    }
};