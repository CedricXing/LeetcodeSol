#include <vector>
using namespace std;

class Solution {
public:
    /*Sol 0
    * Dynamic Programming
    * dp[i] means the longest increasing subsequence up to position i.
    * The subproblem is not only about dp[i] or dp[i-1].
    * dp[i] can be computed by dp[0~i-1].
    */
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0 or nums.size() == 1)
            return nums.size();
        vector<int> dp(nums.size(),1);
        int maxLen = 1;
        for(int i = 1;i < nums.size();++i){
            for(int j = 0;j < i;++j){
                if(nums[j] < nums[i] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            maxLen = max(maxLen,dp[i]);
        }
        return maxLen;
    }

    /* Sol 1
    * Binary search
    * Refer to https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation 
    * for detailed explanation
    */
    int lengthOfLIS1(vector<int> &nums){
        if(nums.size() == 0 or nums.size() == 1)
            return nums.size();
        vector<int> tails(nums.size(),0);
        int size = 0;
        for(auto x : nums){
            int i = 0,j = size;
            while(i < j){
                int middle = (i+j)/2;
                if(tails[middle] < x) i = middle + 1;
                else j = middle;
            }
            tails[i] = x;
            if(i == size) ++size;
        }
        return size;
    }
};