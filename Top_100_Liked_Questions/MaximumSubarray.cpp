#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = INT_MIN;
        int temp = 0;
        for(auto v:nums){
            temp += v;
            maxSub = max(maxSub,temp);
            if(temp < 0)
                temp = 0;
        }
        return maxSub;
    }
};