using namespace std;

struct ListNode {
    int val;
    ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*Sol 0
    * Get the length of each ListNode first.
    * Easy to understand.
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        while(lenA > lenB){
            headA = headA->next;
            --lenA;
        }
        while(lenB > lenA){
            headB = headB->next;
            --lenB;
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }

    int getLength(ListNode *head){
        int len = 0;
        while(head != nullptr){
            head = head -> next;
            ++len;
        }
        return len;
    }

    /*Sol 1 Using maths trick
    * If headA has (a+m) nodes, headB has (b+m) nodes.
    * We assume a>b and m indicates the length of their intersection nodes.
    * We move one step in both lists each time using pointA and pointB, and when it comes to the tail of ListB, there are
    * (a+m)-(b+m)=(a-b) nodes left in ListA. Then we set pointB to headA and continue. When pointA is null,
    * pointB has move (a-b) nodes in ListA, now we set pointA to headB and continue. After b steps, pointA and pointB will
    * meet at the intersection.
    * Very smart solution.
    */
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB){
        ListNode *pointA = headA,*pointB = headB;
        while(pointA != pointB){
            pointA = (pointA == nullptr) ? headB : pointA->next;
            pointB = (pointB == nullptr) ? headA : pointB->next;
        }
        return pointA;
    }

};