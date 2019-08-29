#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	/* Sol 0
	* Use recursion to do reverse automatically.
    * Idea from alex_tsitsura.
	*/
    ListNode *temp;
    bool isPalindrome1(ListNode* head) {
        temp = head;
        return check(head);
    }

    bool check(ListNode *p){
        if(p==nullptr) return true;
        bool result = check(p->next) && (p->val==temp->val);
        temp = temp->next;
        return result;
    }

	/* Sol 1
	* Use two pointers: a fast one(move two steps one time) and a slow one to find the middle pointer of the linked list.
    * Then reverse the half list(no matter which half). Compare the two half linked lists.
    * This method will change the original linked list.
    * Optimization: reverse the first half linked list when the slow pointer moves.
	*/
    bool isPalindrome(ListNode *head){
        if(head == nullptr or head->next == nullptr) return true;
        ListNode *fast = head->next, *slow = head,*pre = nullptr;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            ListNode *nextP = slow->next;
            slow->next = pre;
            pre = slow;
            slow = nextP;
        }
        ListNode *newP = (fast->next==nullptr) ? slow->next : slow->next->next;
        slow->next = pre;
        while(slow!= nullptr){
            if(slow->val != newP->val)
                return false;
            slow = slow->next;
            newP = newP->next;
        }
        return true;
    }
};