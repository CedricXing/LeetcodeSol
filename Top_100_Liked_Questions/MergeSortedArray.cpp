#include <vector>
using namespace std;

class Solution {
public:
    /* Sol 0
	* Obviously, we should compare elements of nums1 and nums2 from the back end to the front end 
    * to avoid moving more elements.
	*/
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1,j = n - 1,pos = m + n - 1;        
        while(i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]) nums1[pos--] = nums1[i--];
            else nums1[pos--] = nums2[j--];
        }
        while(j >= 0){ // only when nums2 has elements left, we need to go on 
            nums1[pos--] = nums2[j--];
        }
        return;
    }
};