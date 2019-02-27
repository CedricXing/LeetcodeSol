using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /* Sol 0
    * Reverse it iteratively
    */
    ListNode* reverseList(ListNode* head) {
        ListNode *begin = nullptr;
        while(head != nullptr){
            ListNode *temp = head->next;
            head->next = begin;
            begin = head;
            head = temp;
        }
        return begin;        
    }

    /*Sol 1
    * Reverse it recursively
    */
    ListNode* reverseList1(ListNode* head){
        if(head == nullptr or head->next == nullptr)
            return head;
        ListNode *newHead = reverseList1(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};