#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* DP solution. O(n*m) time/space complexity.  
    * Use dp[i][j] to indicate the result of s[0,...,i-1] and t[0,...,j-1].
    * If s[i]==t[j], it has two choices:
    *   I. use s[i] -> dp[i+1][j+1] = dp[i][j]
    *   II. don't use s[i] -> dp[i+1][j+1] = dp[i][j+1]
    * So for the case where s[i]==t[j], dp[i+1][j+1] = dp[i][j]+dp[i][j+1]
    * Else if s[i]!=t[j], obviously, dp[i+1][j+1] = dp[i][j+1]
	*/
    int numDistinct(string s, string t) {
        int len1 = s.size(),len2 = t.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));// !!!!! Important: now test cases have been changed. If you still use 'int', you will get an overflow error as there is a '+' operation.
        dp[0][0] = 1;                                       // Consider changing it to 'long' or 'long long'
        for(int i = 1;i <= len1;++i){
            dp[i][0] = 1; // if t == "", we count as one substring
            for(int j = 1;j <= len2;++j){
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[len1][len2];    
    }

    /* Sol 1
	* Optimized sol 0 to use a singe line array.
	*/
    int numDistinct1(string s,string t){
        int len1 = s.size(),len2 = t.size();
        vector<int> dp(len2+1,0);
        dp[0] = 1;
        for(int i = 1;i <= len1;++i){
            int pre = 1;
            for(int j = 1;j <= len2;++j){
                int temp = dp[j];
                if(s[i-1] == t[j-1]) dp[j] += pre;
                pre = temp;
            }
        }
        return dp[len2];
    }
};