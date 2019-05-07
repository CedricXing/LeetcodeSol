#include <vector>
#include <queue>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
    /* Sol 0
    * Divide and Conquer
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len==0) return nullptr;
        while(len > 1){
            for(int i = 0;i < len / 2;++i)
                lists[i] = mergeTwoLists(lists[i],lists[len-1-i]);
            len = (len+1)/2;
        }
        return lists.front();
    }

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
    * Use minimum heap
    */
    struct cmp{
        bool operator()(const ListNode *p,const ListNode *q){
            return p->val > q->val;
        }
    };

    ListNode* mergeKLists1(vector<ListNode*>& lists){
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(auto p:lists){
            if(p!=nullptr)  pq.push(p);
        }
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while(!pq.empty()){
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if(cur->next != nullptr) pq.push(cur->next);
        }
        return dummy.next;
    }
};