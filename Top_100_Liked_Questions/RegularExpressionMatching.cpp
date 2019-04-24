#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /* Sol 0
    * ###Dynamic programming
    * 1, If p.charAt(j) == s.charAt(i) :  dp[i][j] = dp[i-1][j-1];
    * 2, If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1];
    * 3, If p.charAt(j) == '*': here are two sub conditions:
    *       1   if p.charAt(j-1) != s.charAt(i) && p.charAt(j-1) != '.': dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
    *       2   if p.charAt(j-1) == s.charAt(i) or p.charAt(j-1) == '.':
    *               dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a 
    *               or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
    *               or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty
    */
    bool isMatch(string s, string p) {
        int lenS = s.length(),lenP = p.length();
        vector<vector<bool>> dp(lenS+1,vector<bool>(lenP+1,false));
        dp[0][0] = true;
        for(int j = 0;j < lenP;++j){
            if(p[j] == '*' && dp[0][j-1]) // assume p cannot start with '*'
                dp[0][j+1] = true;
        }
        for(int i = 0;i < lenS;++i){
            for(int j = 0;j < lenP;++j){
                if(s[i] == p[j] || p[j] == '.')
                    dp[i+1][j+1] = dp[i][j];
                else if(p[j] == '*'){
                    if(s[i] != p[j-1] && p[j-1] != '.')
                        dp[i+1][j+1] = dp[i+1][j-1];
                    else dp[i+1][j+1] = dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1];
                }
            }
        }
        return dp[lenS][lenP];
    }
};