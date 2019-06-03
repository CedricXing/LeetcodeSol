#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Step 0: find the largest index i that nums[i-1] < nums[i],if no such i exists, inverse the entire array.
    * Step 1: find the minimum number minNumPos from index i to the end that nums[minNumpos] > nums[i-1]
    * Step 2: Swap nums[i-1] and nums[minNumpos]
    * sort array from index i to the end
	*/
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0)  return;
        int i,minNumPos = -1;
        for(i = nums.size()-1;i >= 1;--i){
            if(nums[i] > nums[i-1]) break;
        }
        if(i > 0 && nums[i] > nums[i-1]){
            for(int j = nums.size()-1;j>=i-1;--j)// in fact , we don't have to scan until i-1 here,
                if(nums[j] > nums[i-1] && (minNumPos == -1 || nums[j] < nums[minNumPos]))//because the array from i to the end
                    minNumPos = j;                                                        //is in descending order. So just find the first one that is larger than nums[i-1]
            int temp = nums[i-1];
            nums[i-1] = nums[minNumPos];
            nums[minNumPos] = temp;
            sort(nums.begin()+i,nums.end());
        }
        else sort(nums.begin(),nums.end());
    }
};