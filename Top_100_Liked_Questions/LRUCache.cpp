#include <unordered_map>
using namespace std;

class LRUCache {
    /* So1 0
    * Use double-linked list and hashtable as the inner data structer
    * Take advantage of the double-linked list to remove a node from the list in O(1)
    */
    struct Node{
        int value;
        int key;
        Node *pre;
        Node *post;
        Node():pre(nullptr),post(nullptr){}
        Node(int key,int value):key(key),value(value),pre(nullptr),post(nullptr){}
    };

private: 
    int cacheCount; // current num of nodes
    int capacity; // maximum capacity
    Node *head,*tail;
    unordered_map<int,Node*> map;
public:
    LRUCache(int capacity) {
        cacheCount = 0;
        this->capacity = capacity;
        head = tail = new Node();
        head->pre = head->post = tail;
        tail->pre = tail->post = head;
    }
    
    void removeNode(Node *node){
        Node *temp = node;
        temp->pre->post = temp->post;
        temp->post->pre = temp->pre;
        if(node == tail)    tail = node->pre;
    }

    void addToHead(Node *node){
        node->post = head->post;
        node->pre = head;
        head->post = node;
        node->post->pre = node;
        if(head == tail)    tail = node;
    }

    int get(int key) {
        if(map.find(key) == map.end())  return -1;
        removeNode(map[key]);
        addToHead(map[key]);
        return map[key]->value;
    }
    
    void put(int key, int value) {
        if(get(key) != -1){
            map[key]->value = value;
            removeNode(map[key]);
            addToHead(map[key]);
            return;
        }
        if(cacheCount == capacity){
            Node *temp = tail;
            removeNode(temp);
            map.erase(temp->key);
            delete temp;
            --cacheCount;
        }
        Node *newNode = new Node(key,value);
        addToHead(newNode);
        map[key] = newNode;
        ++cacheCount;
    }
};