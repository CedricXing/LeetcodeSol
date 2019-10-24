#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	/* Sol 0
	* The problem can be solved in O(min(logm,logn)). 
    * Refer to https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn)))-solution-with-explanation
    * for more explanations.
	*/
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int left = 0,right = nums1.size(), mid = (nums1.size()+nums2.size()+1) / 2;
        int current_i, current_j;
        double result1, result2;
        while(left <= right){
            current_i = left + (right - left) / 2;
            current_j = mid - current_i;
            if(current_i < nums1.size() && current_j > 0 && nums2[current_j-1] > nums1[current_i])
                left = current_i + 1;
            else if(current_i > 0 && current_j < nums2.size() && nums2[current_j] < nums1[current_i-1])
                right = current_i - 1;
            else{
                if(current_i == 0) result1 = nums2[current_j - 1];
                else if(current_j == 0) result1 = nums1[current_i - 1];
                else result1 = max(nums1[current_i - 1],nums2[current_j - 1]);
                break;
            }
        }
        if((nums1.size() + nums2.size()) % 2 != 0) return result1;
        if(current_i == nums1.size()) result2 = nums2[current_j];
        else if(current_j == nums2.size()) result2 = nums1[current_i];
        else result2 = min(nums1[current_i],nums2[current_j]);
        return (result1 + result2) / 2;
    }
};
