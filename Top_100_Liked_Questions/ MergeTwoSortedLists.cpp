#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
    /* Sol 0
    * Recursive way
    */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)   return l2;
        if(l2 == nullptr)   return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l2->next,l1);
            return l2;
        }
    }

    /* Sol 1
    * Iterative way
    */
    ListNode* mergeTwoLists1(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur=cur->next;
        }
        cur->next = (l1==nullptr)?l2:l1;
        return dummy.next;
    }
};