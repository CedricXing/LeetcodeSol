#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(),0),right(height.size(),0);
        int maxLeft = 0,maxRight = 0;
        for(int i = 0,j = height.size() - 1;i < height.size(),j >= 0;++i,--j){
            if(height[i] > maxLeft)
                maxLeft = height[i];
            left[i] = maxLeft;
            if(height[j] > maxRight)
                maxRight = height[j];
            right[j] = maxRight;
        }
        int result = 0;
        for(int i = 0;i < height.size();++i){
            result += min(left[i],right[i]) - height[i];
        }
        return result;
    }
};