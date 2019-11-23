#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
class Solution {
public:
    Node *tail;
    Node* flatten(Node* head) {
        tail = nullptr;
        flatten_list(head);
        return head;
    }

    void flatten_list(Node *head){
        Node *p = head;
        while(p != nullptr){
            if(p->child != nullptr){
                Node *next_node = p->next;
                p->next = p->child;
                p->child = nullptr;
                p->next->prev = p;
                flatten_list(p->next);
                tail->next = next_node;
                if(next_node != nullptr) next_node ->prev = tail;
                p = next_node;
            }
            else {
                tail = p;
                p = p->next;
            }
        }
    }
};