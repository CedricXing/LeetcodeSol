#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* In order not to use extra space, we mark the position nums[i]-1 as negative to represent
    * that nums[i]-1 has appeared.
	*/
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(int i = 0;i < nums.size();++i){
            int haveAppeared = abs(nums[i]) - 1;// index starts from 0
            nums[haveAppeared] = -abs(nums[haveAppeared]);// mark negative means it has appeared
        }
        for(int i = 0;i < nums.size();++i){
            if(nums[i] > 0) result.push_back(i+1);
        }
        return result;
    }
    
    /* Sol 1
	* Because each element ranges from 1 to n. If we want to sort the array, 
    * the nums[i] will be probably set to the position nums[i]-1.
    * So we scan the array, and for the position i, if nums[i]-1 != i, we swap nums[i] to the correct position which is nums[i]-1.
    * Note : if nums[i] is equal to nums[nums[i]-1], it means the duplicated element. So skip the case to prevent the dead loop.
    * Finally, we just need to check the position that nums[i]-1 != i.
    * Analysis: obviously no extra space is used. 
    * Because we just need to put n element into its correct position, and 
    * each swap can make an element be in the correct position, so we need at most n swaps.
    * The overall time complexity is O(n).
	*/
    vector<int> findDisappearedNumbers1(vector<int>& nums){
        vector<int> result;
        for(int i = 0;i < nums.size();++i){
            while(nums[i]-1 != i && nums[i] != nums[nums[i]-1]){
                swap(nums,i,nums[i]-1);
            }
        }
        for(int i = 0;i < nums.size();++i)
            if(nums[i]-1 != i) result.push_back(i+1);
        return result;
    }

    void swap(vector<int> &nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};