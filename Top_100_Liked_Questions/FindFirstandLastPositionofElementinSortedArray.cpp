#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Use the C++ STL lower_bound and upper_bound function to solve the problem.
	*/
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        if(nums.size() == 0) return result;
        int lb = lower_bound(nums,target), ub = upper_bound(nums,target) - 1;
        if(lb == nums.size() or nums[lb] != target) return result;
        result[0] = lb;
        result[1] = ub;
        return result;
    }

    int lower_bound(vector<int> &nums,int target){
        int left = 0, right = nums.size();
        while(left < right){
            int middle = left + (right - left) / 2;
            if(nums[middle] < target) left = middle + 1;
            else right = middle;
        }
        return left;
    }

    int upper_bound(vector<int> &nums,int target){
        int left = 0, right = nums.size();
        while(left < right){
            int middle = left + (right - left) / 2;
            if(nums[middle] <= target) left = middle + 1;
            else right = middle;
        }
        return left;
    }
};