#include <iostream>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
	/* Sol 0
	* Use two pointers to scan in only one pass.
    * I'd like to use a dummy node to simplify the code.
	*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first=head,*pre=new ListNode(-1);
        pre->next=head;
        for(int i = 0;i < n;++i)    first=first->next;
        while(first != nullptr){
            first = first->next;
            pre = pre->next;
        }
        ListNode *temp = pre->next;
        pre->next = temp->next;
        if(temp==head) head=head->next;
        delete temp;
        return head;
    }
};