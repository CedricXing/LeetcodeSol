#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/* Sol 0
	* As we cannot reverse the lists, a stack is a good choice to solve the problem.
	*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1,st2;
        for(ListNode *p = l1;p != nullptr;p = p->next) st1.push(p->val);
        for(ListNode *p = l2;p != nullptr;p = p->next) st2.push(p->val);
        ListNode *head = nullptr;
        int sum = 0;
        while(!st1.empty() || !st2.empty() || sum != 0){
            if(!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }
            if(!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }
            ListNode *node = new ListNode(sum % 10);
            sum /= 10;
            node -> next = head;
            head = node;
        }
        return head;
    }
};
