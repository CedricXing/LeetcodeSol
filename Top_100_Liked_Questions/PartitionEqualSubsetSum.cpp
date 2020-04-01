#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* 可以建模成一个0-1背包问题；
    * 首先算出总和，如果不能被2整除说明肯定不行；
    * 如果可以，则背包式解决。这里的空间复杂度可以继续优化。
	*/
    bool canPartition(vector<int>& nums) {
        int sum_ = 0;
        for(auto n : nums) sum_ += n;
        if(sum_ % 2 != 0) return false;
        
        int target = sum_ / 2;
        vector<vector<int> > dp(nums.size() + 1,vector<int>(target + 1));
        dp[0][0] = 1;
        for(int i = 0;i < nums.size();++i){
            dp[i + 1][0] = 1;
            for(int j = 0;j <= target;++j){
                if(nums[i] > j) dp[i + 1][j] = dp[i][j];
                else dp[i + 1][j] = dp[i][j] || dp[i][j - nums[i]];
            }
        }
        return dp[nums.size()][target];
    }
};