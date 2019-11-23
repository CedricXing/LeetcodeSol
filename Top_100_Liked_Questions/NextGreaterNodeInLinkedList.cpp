#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> list;
        for(ListNode *p = head;p != nullptr;p = p->next){list.push_back(p->val);}
        vector<int> result(list.size(),0);
        stack<int> st;
        int i = 0;
        for(ListNode *p = head;p != head;p = p->next,++i){
            while(!st.empty() && list[st.top()]<p->val){
                result[st.top()] = p->val;
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};