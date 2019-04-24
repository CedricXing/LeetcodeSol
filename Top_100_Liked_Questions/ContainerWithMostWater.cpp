#include <vector>
using namespace std;

class Solution {
public:
    /* Sol 0
    * ###Greedy O(n)
    * Use two pointer : left and right
    * Assume that height[left] <= height[right] now and we left shift the right pointer. 
    * It will comes two following situations:
    * 1.height[new_right] >= height[original_right]. 
    *       Obviously, the height of the container is still height[left], but the width is smaller.
    * 2.height[new_right] < height[original_right]. 
    * In this case, the width of the container is smaller and the 
    * height is min(height[left],height[new_right]) <= height[left]=original height.
    The both situations cannot lead to a lager area. So we just need to right shift the left pointer.
    */
    int maxArea(vector<int>& height) {
        int result = 0,i = 0,j = height.size() - 1;
        while(i < j){
            result = max(result,min(height[i],height[j])*(j-i));
            if(height[i] <= height[j])
                ++i;
            else --j;
        }
        return result;
    }
};