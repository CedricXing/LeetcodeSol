#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* The trick usually used in searching the range
	*/
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        if(nums.size() == 0) return result;
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int middle = left + (right - left) / 2;
            if(nums[middle] < target) left = middle + 1;
            else right = middle;
        }
        if(nums[left] == target) result[0] = left;
        right = nums.size() - 1;
        while(left < right){
            int middle = left + (right - left) / 2 + 1; // here must +1 when searching the right range, or the pointer middle may not move 
            if(nums[middle] > target) right = middle - 1;
            else left = middle;
        }
        if(nums[right] == target) result[1] = right;
        return result;
    }
};