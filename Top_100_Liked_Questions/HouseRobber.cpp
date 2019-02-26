#include <vector>
using namespace std;

class Solution {
public:
    /*Sol 0
    * DP solution
    * dp[i] = max(dp[i-1],dp[i-2]+nums[i])
    */
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        else if(nums.size() == 1) return nums[0];
        int *results = new int[nums.size()];
        results[0] = nums[0];
        results[1] = max(nums[0],nums[1]);
        for(int i = 2;i < nums.size();++i){
            results[i] = max(results[i-1],results[i-2] + nums[i]);
        }
        return results[nums.size()-1];
    }
};