#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
	/* Sol 0
	* O(1) space complexity, O(n) time complexity
    * Iterate the list three times.
    *   I. scan the list and insert the new node after the original one. 【e.g. A->B->C turn into A->A'->B->B'->C->C'】
    *       The random pointer of each new node is just the same as that of the original one.
    *   II. scan the list again and modify the random pointer of each node to its next node. (dismiss nullptr random pointer)
    *   III. scan the list and split it into two lists. 
	*/
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node *p = head;
        while(p != nullptr){
            Node *temp = new Node(p->val,p->next,p->random);
            p->next = temp;
            p = temp->next;
        }
        p = head;
        while(p != nullptr){
            if(p->next->random != nullptr)
                p->next->random = p->next->random->next;
            p = p->next->next;
        }
        Node *n_head = nullptr,*current = nullptr;
        p = head;
        while(p != nullptr){
            if(n_head == nullptr) n_head = p->next;
            else current->next = p->next;    
            current = p->next;
            p->next = p->next->next;
            p = p->next;
        }
        return n_head;
    }
};