#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size(),pointer = 0;
        for(int i = 0;i < size;++i){
            if(nums[i] != 0)    nums[pointer++] = nums[i];
        }
        for(int i = pointer;i < size;++i)   nums[i] = 0;
    }
};