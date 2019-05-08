#include <vector>
using namespace std;

class Solution {
public:
    /* Sol 0
    * The array is divided into two ascending part. So firstly, check whether nums[mid]
    * and target are in the same part. If so, just do normal binary search.
    * If not, do a trick to simplify the code. -> If nums[mid] is in smaller part (right side), represent
    * it by INT_MAX, otherwise INT_MIN. Then we can do normal binary search again.
    */
    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size() - 1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] == target) return mid;
            int num = (nums[mid] < nums[0]) == (target < nums[0]) ?
                        nums[mid]:
                        (target < nums[0]) ? INT_MIN : INT_MAX;
            if(num < target) left = mid + 1;
            else right = mid - 1;
        }        
        return -1;
    }
};