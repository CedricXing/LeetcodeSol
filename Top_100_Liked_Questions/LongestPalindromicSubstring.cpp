#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /* Sol 0
    * DP
    */
    string longestPalindrome(string s) {
        int len = s.length();
        vector<vector<int>> dp(len,vector<int>(len,0));
        int start=0,maxlen=-1;
        string result;
        for(int i = len-1;i >= 0;--i){
            for(int j = i;j < len;++j){
                dp[i][j] = s[i]==s[j] && (j-i < 2 || dp[i+1][j-1]);
                if(dp[i][j] && (j-i+1 > maxlen)){
                    maxlen = j-i+1;
                    result = s.substr(i,maxlen);
                }
            }
        }
        return result;
    }

    /*Sol 1
    * The number of candidate substrings is n^2, but the number of potential
    * middle point of a palindromic is only n.
    */
    string result;
    int maxlen;
    string longestPalindrome1(string s) {
        maxlen = -1;
        for(int i = 0;i < s.length();++i){
            checkLongest(s,i,i); // case for single middle point
            checkLongest(s,i,i+1);// case for two middle points
        }
        return result;
    }

    void checkLongest(string s,int left,int right){
        while(left>=0 && right <= s.length()-1){
            if(s[left]==s[right]){
                --left;
                ++right;
            }
            else break;
        }
        if(right-left-1 > maxlen){
            maxlen = right-left-1;
            result = s.substr(left+1,maxlen);
        }
    }
};