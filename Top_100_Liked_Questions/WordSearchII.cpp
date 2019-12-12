#include <vector>
#include <string>
using namespace std;

struct TrieNode{
    int idx;
    TrieNode *next[26];
    TrieNode():idx(-1){memset(next,0,sizeof(next));};
};

class Solution {
public:
	/* Sol 0
	* Use a Trie to find words efficiently.
    * Firstly, build the Trie using words, then for each char in board, search the word in the trie.
    * Note when backtracking, recover the char from '#' to its original value.
	*/
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> result;
        TrieNode *root = new TrieNode();
        buildTrie(root,words);
        for(int i = 0;i < board.size();++i){
            for(int j = 0;j < board[0].size();++j){
                dfs(result,board,i,j,root,words);
            }
        }
        return result;
    }

    void dfs(vector<string> &result, vector<vector<char> > &board,int i,int j,TrieNode *p,vector<string> &words){
        char c = board[i][j];
        if(c == '#' || p->next[c - 'a'] == nullptr) return;
        p = p->next[c-'a'];
        if(p->idx != -1) {
            result.push_back(words[p->idx]);
            p->idx = -1; // avoid duplicated word
        }
        board[i][j] = '#';
        if(i > 0) dfs(result,board,i-1,j,p,words);
        if(j > 0) dfs(result,board,i,j-1,p,words);
        if(i+1 < board.size()) dfs(result,board,i+1,j,p,words);
        if(j+1 < board[0].size()) dfs(result,board,i,j+1,p,words);
        board[i][j] = c;
    }

    void buildTrie(TrieNode *root,vector<string>& words){
        for(int i = 0;i < words.size();++i){
            TrieNode *p = root;
            for(auto c:words[i]){
                if(p->next[c-'a']==nullptr) p->next[c-'a'] = new TrieNode();
                p = p->next[c-'a'];
            }
            p->idx = i;
        }
    }
};