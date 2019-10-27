#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1),*current = head,*first = dummy;
        dummy->next = head;
        while(current != nullptr && current->next != nullptr){
            if(current->val == current->next->val){
                int val = current->val;
                while(current!=nullptr && current->val == val){
                    current = current->next;
                }
            }
            else {
                first->next = current;
                first = current;
                current = current->next;
            }
        }
        first->next = current;
        return dummy->next;
    }
};