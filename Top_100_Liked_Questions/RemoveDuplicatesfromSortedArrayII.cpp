#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Similar to the original problem, we can use a flag 'appear_twice' 
    * to indicate whether the current element has appeared twice
	*/
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int current_pos = 0;
        bool appear_twice = false;
        for(int i = 1;i < nums.size();++i){
            if(nums[i] == nums[current_pos]){
                if(!appear_twice){
                    appear_twice = true;
                    nums[++current_pos] = nums[i];
                }
            }
            else{
                appear_twice = false;
                nums[++current_pos] = nums[i];
            }
        }
        return current_pos + 1; // plus 1 to get the length    
    }

    /* Sol 1
	* More elegant solution.
	*/
    int removeDuplicates2(vector<int>& nums) {
        int len = 0;
        for(auto num : nums){
            if(len < 2 || num > nums[len-2])
                nums[len++] = num;
        }
        return len;
    }

};