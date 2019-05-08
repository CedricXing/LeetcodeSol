#include <vector>
using namespace std;

class Solution {
public:
    /*Sol 0
    * Just like Linked List Cycle II
    * Find the cycle O(n)
    */
    int findDuplicate(vector<int>& nums) {
        int slow = 0,fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast)  break;
        }
        fast = 0;
        while(slow != fast){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }

    /* Sol 1
    * Binary search O[n(logn)]
    */
    int findDuplicate1(vector<int>& nums){
        int left = 0,right = nums.size()-1;
        while(left<right){
            int middle = (left+right) / 2;
            int count = 0;
            for(auto num:nums){
                if(num <= middle) ++count;
            }
            if(count>middle) right = middle;
            else left = middle+1;
        }
        return left;
    }
};