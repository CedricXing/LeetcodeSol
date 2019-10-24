#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* The max area Rectangle with the height of height[i] must have the width of (rightMost[i]-leftMost[i]+1)
    * where leftMost[i] represents the minimum position p with heights[p]>=heights[i],
    * rightMost[i] represents the maximum position q with heights[q] >= heights[i].
    * So if we can compute the arrays leftMost and rightMost in O(n),the total time complexity will be O(n). 
    * The p = leftMost[p] - 1 statement ensures that each element before i will be visited at most once. So it's O(n).
	*/
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        int size = heights.size();
        vector<int> leftMost(size,0);
        vector<int> rightMost(size,size - 1);
        for(int i = 0,j = size - 1;i < heights.size();++i,--j){
            int p = i - 1,q = j + 1;
            while(p >= 0 && heights[p] >= heights[i])
                p = leftMost[p] - 1;
            leftMost[i] = p + 1;
            while(q < size && heights[q] >= heights[j])
                q = rightMost[q] + 1;
            rightMost[i] = q - 1;
        }
        int result = 0;
        for(int i = 0;i < size;++i)
            result = max(result,heights[i] * (rightMost[i]-leftMost[i] + 1));
        return result;
    }
};