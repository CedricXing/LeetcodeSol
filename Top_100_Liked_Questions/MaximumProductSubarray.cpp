#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    /* Sol0 思路
    * 分别记录到目前为止的最大值和最小值，因为最大值可能由前一个最大值乘以正数得到，也可以由前一个最小值乘以负数得到
    * 关键点在于也要记录最小值
    * time complexity O(n), space complexity O(1)
    */
    int maxProduct(vector<int>& nums) {
        int _min = nums[0],_max = nums[0];
        int result = nums[0];
        for(int i = 1;i < nums.size();++i){
            int tempMax = _max;
            _max = max(max(_max*nums[i],_min*nums[i]),nums[i]);//编译器会优化这两次乘法吗？
            _min = min(min(tempMax*nums[i],_min*nums[i]),nums[i]);//如果编译器能追踪tempMax = _max这次赋值，那么就可以优化？
            result = max(_max,result);
        }
        return result;
    }
};