#include <vector>
#include <map>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
	/* Sol 0
	* Use a map to store the prefix sum that has appeared. If a value appears again,
    * it means that there is a consecutive list that sums to 0.
	*/
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0),*current = &dummy;
        dummy.next = head;
        map<int,ListNode*> mp;
        int pre_sum = 0;
        while(current != nullptr){
            pre_sum += current->val;
            if(mp.count(pre_sum)){ // find a concsecutive list that sums to 0
                ListNode *p = mp[pre_sum]->next;
                int temp = pre_sum;
                while(p != current){
                    temp += p->val;
                    mp.erase(temp);
                    p = p->next;
                }
                mp[pre_sum]->next = current->next;
            }
            else mp[pre_sum] = current;
            current = current->next;
        }
        return dummy.next;
    }
};