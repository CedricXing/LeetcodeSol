#include <set>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    /* Sol 0
    * High space complexity.(O(n))
    * Using a set to store the address.
    * O(n) time complexity.
    */
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> s;
        if(!head)   return nullptr;
        ListNode *p = head;
        while(p != nullptr && s.find(p) != s.end()){
            s.insert(p);
            p = p->next;
        }
        return p;
    }
    /* Sol 1
    * Detect cycle using two pointers: fastP moves two steps once while
    * slowP moves only one step.
    * Then set fastP to head and move one step everytime.Then they will meet
    * at the entry.
    * WHY? Just draw a picture.
    * O(1) space complexity and O(n) time complexity.
    */
    ListNode *slowP,*fastP;
    ListNode *detectCycle1(ListNode *head){
        if(!hasCycle(head))   return nullptr;
        fastP = head;
        while(fastP != slowP){
            fastP = fastP->next;
            slowP = slowP->next;
        }
        return slowP;
    }

    bool hasCycle(ListNode *head) {
        if(!head || !head->next)   return false;
        slowP = head,fastP = head;
        while(slowP != nullptr && fastP != nullptr){
            if(!fastP->next)    return false;
            slowP = slowP->next;
            fastP = fastP->next->next;
            if(slowP == fastP)  return true;
        }
        return false; 
    }
};