#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Just like 3Sum, use two pointers.
    * Time complexity O(n*n)
	*/
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return -1;//error
        sort(nums.begin(),nums.end());
        int result = 0, minDelta = INT32_MAX;
        for(int i = 0;i < nums.size();++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1, right = nums.size()-1;
            int tempDelta, tempTarget = target - nums[i];
            while(left < right){
                tempDelta = tempTarget - nums[left] - nums[right];
                if(abs(tempDelta) < abs(minDelta)) minDelta = tempDelta;
                if(tempDelta == 0) return target;
                else if(tempDelta > 0) ++left;
                else --right;
            }
            result = target - minDelta;
        }
        return result;
    }
};

int main(){
    int arr[] = {1,2,5,10,11};
    vector<int> vec(arr,arr+5);
    Solution solution;
    cout << solution.threeSumClosest(vec,12);
}