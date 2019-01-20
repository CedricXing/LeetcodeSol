#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /* Sol 0
    * Solving recursively.
    * Using an array to speed up.(DP)
    */
    bool wordBreak(string s, vector<string>& wordDict) {
        int *arr = new int[s.length()];
        memset(arr,1,s.length()*4);
        bool result = wordBreak(s,wordDict,arr,0);
        delete []arr;
        return result;
    }

    bool wordBreak(string s,vector<string>& wordDict,int *arr,int index){
        if(index == s.length())
            return true;
        if(!arr[index]) return false;
        for(const string& word : wordDict){
            if(index + word.length() > s.length() || word != s.substr(index,word.length()))
                continue;
            bool result = wordBreak(s,wordDict,arr,index + word.length());
            if(result)  return true;
            else arr[index + word.length()] = 0;
        }
        return false;
    }

    /* Sol 1
    * Standard DP solution.
    */
    bool wordBreakDP(string s, vector<string>& wordDict){
        int *arr = new int[s.length()+1];
        memset(arr,0,s.length()*4 + 4);
        arr[0] = 1;
        for(int i = 1;i <= s.size();++i){
            for(const string& word : wordDict){
                if(i >= word.length() && arr[i-word.length()] && word == s.substr(i-word.length(),word.length())){
                    arr[i] = 1;
                    break;
                }
            }
        }
        return arr[s.length()];
    } 
};
