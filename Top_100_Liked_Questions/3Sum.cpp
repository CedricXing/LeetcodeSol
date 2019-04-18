#include <vector>
using namespace std;

class Solution {
public:
    /*Sol 1
    * Sort first, then fix the first number. Use two pointers.
    * Process duplicates.
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<3)  return result;
        sort(nums.begin(),nums.end());
        for(int i = 0;i <= nums.size()-3;++i){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int left = i + 1,right = nums.size()-1;
            while(left<right){
                if(left-i>1&&nums[left]==nums[left-1]){
                    ++left;continue;
                }
                if(right<nums.size()-1&&nums[right]==nums[right+1]){
                    --right;continue;
                }
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == 0){
                    int temp[]={nums[i],nums[left],nums[right]};
                    vector<int> vec(temp,temp+3);
                    result.push_back(vec);
                    ++left;--right;
                }
                else if(sum < 0) ++left;
                else --right;
            }
        }
        return result;
    }
};