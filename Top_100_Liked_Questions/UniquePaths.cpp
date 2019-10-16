#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Dynamic Programming
	*/
    int uniquePaths(int m, int n) {
        if(m<=1 || n<=1) return 1;
        vector<vector<int>> dp(m,vector<int>(n,1));
        dp[0][0] = 0;
        for(int i = 1;i < m;++i){
            for(int j = 1;j < n;++j)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        return dp[m-1][n-1];
    }

	/* Sol 1
	* Dynamic Programming with space optimization
	*/
    int uniquePaths1(int m, int n){
        if(m<=1 || n<=1) return 1;
        vector<int> dp(n,1);
        for(int i = 1;i < m;++i){
            for(int j = 1;j < n;++j){
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};