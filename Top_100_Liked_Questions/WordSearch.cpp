#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0;i < board.size();++i){
            for(int j = 0;j < board[0].size();++j){
                if(exist(board,i,j,0,word))
                    return true;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>> &board,int i,int j,int pos,string word){
        if(i<0||i>=board.size()||j<0||j>=board[0].size())    return false;
        if(board[i][j] != word[pos]) return false;
        if(pos + 1 == word.size())  return true;
        char temp = board[i][j];
        board[i][j] = '0';
        bool result = exist(board,i-1,j,pos+1,word) || exist(board,i+1,j,pos+1,word)||
        exist(board,i,j-1,pos+1,word) || exist(board,i,j+1,pos+1,word);
        board[i][j] = temp;
        return result;
    }
};