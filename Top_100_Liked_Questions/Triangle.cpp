#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* DP solution. O(n^2) time and space complexity.
    * Can be easily optimized to O(n) space complexity.
	*/
    int minimumTotal(vector<vector<int> >& triangle) {
        vector<vector<int> > dp;
        int height = triangle.size();
        if(height == 0) return 0;
        dp.push_back(triangle[height-1]);
        for(int i = height - 2;i >= 0;--i){
            int num = triangle[i].size();
            vector<int> temp_dp(num,0);
            for(int j = 0;j < num;++j){
                int value = min(dp[height-2-i][j],dp[height-2-i][j+1]);
                // if(j > 0) value = min(value,dp[height-2-i][j-1]);
                temp_dp[j] = triangle[i][j] + value;
            }
            dp.push_back(temp_dp);
        }
        return dp[height-1][0];
    }

	/* Sol 1
	* O(n) space complexity.
	*/
    int minimumTotal1(vector<vector<int> >& triangle) {
        vector<int> dp;
        int height = triangle.size();
        if(height == 0) return 0;
        dp = triangle[height-1];
        for(int i = height - 2;i >= 0;--i){
            int num = triangle[i].size();
            for(int j = 0;j < num;++j){
                dp[j] = min(dp[j],dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};