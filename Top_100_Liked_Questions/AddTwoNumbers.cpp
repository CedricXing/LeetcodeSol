#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    /* Sol 0
    * Use a sentinel.
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p=l1,*q=l2,head=ListNode(-1);
        ListNode *tail=&head;
        int sum = 0;
        while(p!=nullptr || q!=nullptr){
            sum /= 10;
            if(p!=nullptr){
                sum += p->val;
                p=p->next;
            }
            if(q!=nullptr){
                sum += q->val;
                q=q->next;
            }
            tail->next = new ListNode(sum%10);
            tail = tail->next;
        }
        if(sum/10 == 1) tail->next = new ListNode(1);
        return head.next;
    }
};