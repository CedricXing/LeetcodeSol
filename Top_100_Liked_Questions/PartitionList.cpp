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
	* The problem is solved by swap the node (not the value).
    * It will be much easier by splitting the list into two new lists and then concatenating them.
	*/
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(-1),*left = &dummy,*current = head,*pre=&dummy;        
        dummy.next = head;
        while(current != nullptr){
            if(current->val < x){
                if(left->next != current){
                    ListNode *temp = left->next;
                    left->next = current;
                    pre->next = current->next;
                    current->next = temp;
                    left = current;
                    current = pre->next;
                }
                else{
                    current = current->next;
                    left = left->next;
                    pre = pre->next;
                }
            }
            else{
                current = current->next;
                pre = pre->next;
            }
        }
        return dummy.next;
    }
};