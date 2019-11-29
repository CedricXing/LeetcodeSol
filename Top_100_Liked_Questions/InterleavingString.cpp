#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	/* Sol 0
	* DP solution. O(mn) time/space complexity
    * can be optimized to O(n) space complexity
	*/
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(),len2 = s2.size();
        if(len1 + len2 != s3.size()) return false;
        vector<vector<int>> dp(len1 + 1,vector<int>(len2 + 1,0));
        for(int i = 0; i < len2;++i){
            if(s2[i] == s3[i]) dp[0][i+1] = 1;
            else break;
        }    
        dp[0][0] = 1;
        for(int i = 1;i <= len1;++i){
            dp[i][0] = (s1[i-1] == s3[i-1]) && dp[i-1][0];
            for(int j = 1;j <= len2;++j){
                dp[i][j] = (s1[i-1] == s3[i+j-1] && dp[i-1][j]) || (s2[j-1] == s3[i+j-1] && dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }

	/* Sol 0
	* Easily transform the above solution to O(n) space complexity.
	*/
    bool isInterleave1(string s1, string s2, string s3) {
        int len1 = s1.size(),len2 = s2.size();
        if(len1 + len2 != s3.size()) return false;
        vector<int> dp(len2 + 1,0);
        dp[0] = 1;
        for(int i = 0; i < len2;++i){
            if(s2[i] == s3[i]) dp[i+1] = 1;
            else break;
        }  
        for(int i = 1;i <= len1;++i){
            dp[0] = (s1[i-1] == s3[i-1]) && dp[0];
            for(int j = 1;j <= len2;++j){ 
                dp[j] = (s1[i-1] == s3[i+j-1] && dp[j]) || (s2[j-1] == s3[i+j-1] && dp[j-1]);
            }
        }
        return dp[len2];
    }
};
