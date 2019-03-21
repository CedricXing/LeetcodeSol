#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums,0,nums.size()-1,k);
    }

    int findKthLargest(vector<int>& nums,int left,int right,int k){
        int pivot = nums[left];
        int j = left;
        for(int i = left+1;i <= right;++i){
            if(nums[i] <= pivot){
                ++j;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        nums[left] = nums[j];
        nums[j] = pivot;
        if(j == (nums.size()-k))
            return nums[j];
        else if(j < (nums.size()-k))
            return findKthLargest(nums,j+1,right,k);
        else return findKthLargest(nums,left,j-1,k);
    }
};