#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Dynamic programming.
    * Only use O(n) space.
	*/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long long> dp(obstacleGrid[0].size(),0);
        for(int i = 0;i < obstacleGrid[0].size();++i){
            if(obstacleGrid[0][i] == 0)
                dp[i] = 1;
            else break;
        }
        for(int i = 1;i < obstacleGrid.size();++i){
            dp[0] = (obstacleGrid[i][0] == 1) ? 0 : dp[0]; 
            for(int j = 1;j < obstacleGrid[0].size();++j){
                if(obstacleGrid[i][j] == 0) dp[j] += dp[j-1];
                else dp[j] = 0;
            }
        }
        return dp[obstacleGrid[0].size() - 1];
    }
};