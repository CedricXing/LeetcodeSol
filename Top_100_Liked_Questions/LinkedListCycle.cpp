using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)   return false;
        ListNode *slowP = head,*fastP = head;
        while(slowP != nullptr && fastP != nullptr){
            if(!fastP->next)    return false;
            slowP = slowP->next;
            fastP = fastP->next->next;
            if(slowP == fastP)  return true;
        }
        return false; 
    }
};