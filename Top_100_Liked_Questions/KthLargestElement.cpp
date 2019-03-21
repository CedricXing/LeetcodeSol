#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        findKthLargest(nums,0,nums.size()-1,k-1);
    }

    int findKthLargest(vector<int>& nums,int left,int right,int k){
        if(left==right)
            return nums[left];
        int pivot = nums[left];
        int j = left;
        for(int i = left;i <= right;++i){
            if(nums[i] <= pivot){
                ++j;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        nums[left] = nums[j];
        nums[j] = pivot;
        if(k < right-j+1)
            return findKthLargest(nums,j+1,right,k);
        else{
            return findKthLargest(nums,left,j,k-right+j-1);
        }
    }
};