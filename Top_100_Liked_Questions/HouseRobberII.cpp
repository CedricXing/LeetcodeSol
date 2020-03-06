#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* 既然首尾不能同时选，那么将原问题拆成两个问题，一个去头，一个去尾。
	*/
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        else if(nums.size() == 1) return nums[0];
        vector<int> nums1(nums.begin(),nums.end() - 1),nums2(nums.begin() + 1,nums.end());
        return max(helper(nums1),helper(nums2));
    }
    
    int helper(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];dp[1] = max(nums[0],nums[1]);
        int result = dp[1];
        for(int i = 2;i < nums.size();++i){
            dp[i] = max(nums[i] + dp[i - 2],dp[i - 1]);
            result = max(dp[i],result);
        }
        return result;
    }
};