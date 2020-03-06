#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* 动态规划。dp[i][j]代表用前i个数字算出j共有多少种解法。
    * 那么dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]] (注意边界问题)
    * 还有一个要注意的地方：在初始化第一行的时候，要考虑数字为0的情况，不能直接设为1，而是要自增，因为如果是0那么应该是两种解法。
	*/
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum_ = 0;
        for(auto n : nums) sum_ += n;
        if(S < -sum_ || S > sum_) return 0;
        vector<vector<int> > dp(nums.size(),vector<int>(2 * sum_ + 1,0));
        dp[0][nums[0] + sum_]++;
        dp[0][sum_ - nums[0]]++;
        for(int i = 1;i < nums.size();++i){
            for(int j = 0;j < 2 * sum_ + 1;++j){
                if(j + nums[i] <= 2 * sum_) dp[i][j] += dp[i - 1][j + nums[i]];
                if(j - nums[i] >= 0) dp[i][j] += dp[i - 1][j - nums[i]];
            }
        }
        return dp[nums.size() - 1][S + sum_];
    }
};