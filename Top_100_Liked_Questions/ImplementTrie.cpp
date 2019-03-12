#include <string>
#include <set>
using namespace std;

class TrieNode{
    public:
    bool isWord;
    TrieNode* next[26];

    TrieNode(){
        isWord = false;
        memset(next,0,sizeof(next));
    }
};

class Trie {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){
        clear(root);
    } 
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(char c:word){
            if(p->next[c-'a'] == nullptr){
                p->next[c-'a'] = new TrieNode();
            }
            p = p->next[c-'a'];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for(char c:word){
            if(p->next[c-'a']==nullptr)
                return false;
            p = p->next[c-'a'];
        }
        if(p->isWord==true)
            return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(char c:prefix){
            if(p->next[c-'a']==nullptr)
                return false;
            p = p->next[c-'a'];
        }
        return true;
    }
    private:
    void clear(TrieNode *p){
        for(int i = 0;i < 26;++i){
            if(p->next[i]!=nullptr)
                clear(p->next[i]);
        }
        delete p;
    }
};

