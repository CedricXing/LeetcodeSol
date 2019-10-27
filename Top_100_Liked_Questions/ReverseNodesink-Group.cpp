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
	* Recursive solution
	*/
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p = head;
        for(int i = 0;i < k;++i){
            if(p == nullptr) return head;
            p = p->next;
        }
        ListNode *pre = reverseKGroup(p,k);
        while(k > 0){
            ListNode *temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
            --k;
        }
        return pre;
    }

	/* Sol 1
	* Iteration solution.
    * No use of dummy node. 
    * Use tail to record the last tail whose next pointer need to be modified later.
	*/
    ListNode* reverseKGroup1(ListNode *head,int k){
        int len = 0;
        for(ListNode *p=head;p!=nullptr;++len,p=p->next) ;
        if(len < k) return head;
        ListNode *current = head,*tail = head;
        while(len >= k){
            ListNode *pre = nullptr,*temp_tail = current;
            for(int i = 0;i < k;++i){
                ListNode* temp = current->next;
                current->next = pre;
                pre = current;
                current = temp;
            }
            if(temp_tail == head) head = pre;
            else {
                tail -> next = pre;
                tail = temp_tail;
            }
            len-=k;
        }
        tail->next = current;
        return head;
    }
};