#include <vector>
using namespace std;

class Solution {
public:
    /* Sol 0
    * Without division and use O(n) time and O(1) space
    */
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);
        int len = nums.size(),right=1;
        for(int i = 1;i < len;++i)  result[i] = result[i-1] * nums[i-1];
        for(int i = len-1;i >= 0;--i){
            result[i]*=right;
            right*=nums[i];
        }
        return result;
    }

    /* Sol 1
    * If division is permitted, take good case of zero.
    * When compute the product of all numbers, count the number of zeros.
    * If there are more than one zero, the result is a zero-array.
    * If there is exactly one zero, then only one position can be non-zero
    */
    vector<int> productExceptSelf1(vector<int>& nums){
        int len = nums.size(),product=1,counter=0;
        vector<int> result(len,0);
        for(auto n:nums){
            if(n==0) {if(++counter>1) break;}
            else product*=n;
        }
        if(counter>1)   return result;
        for(int i = 0;i < len;++i){
            if(counter==0)  result[i] = product / nums[i];
            else if(nums[i]==0)  result[i] = product;
        }
        return result;
    }
};