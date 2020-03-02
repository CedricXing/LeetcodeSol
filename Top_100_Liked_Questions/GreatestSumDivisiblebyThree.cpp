#include <vector>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int result = 0,left_two = 20000,left_one = 20000; // 这边因为nums[i]都是不超过10000的
        for(auto a : nums){
            result += a;
            if(a % 3 == 1){
                left_two = min(left_two,left_one + a);
                left_one = min(left_one,a);
            }
            else if(a % 3 == 2){
                left_one = min(left_one,left_two + a);
                left_two = min(left_two,a);
            }
        }
        if(result % 3 == 0) return result;
        else if(result % 3 == 1) return result - left_one;
        else return result - left_two;
    }
};
