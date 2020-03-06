#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* 排序法，O(nlgn)
    * 首先排序，然后逐个对比每个位置上的元素，看是否变过。
	*/
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());
        int i = 0,j = nums.size() - 1;
        while(i < nums.size() && nums[i] == sorted[i]) ++i;
        while(j > i && nums[j] == sorted[j]) --j;
        
        return j - i + 1;
    }
	/* Sol 0
	* O(n)解法。
    * 首先计算出两个数组，min_v[i]代表i右边最小的元素，max_v[i]代表i左边最大的元素。
    * 那么如果i要保持不动，就得比min_v[i]小且比max_v[i]大。
	*/
    int findUnsortedSubarray1(vector<int>& nums) {
        if(nums.empty()) return 0;
        int size = nums.size();
        vector<int> min_v(size),max_v(size);
        int min_e = INT32_MAX,max_e = INT32_MIN;
        for(int i = 0;i < nums.size();++i) {
            max_v[i] = max_e = max(nums[i],max_e);
        }
        for(int j = size - 1;j >= 0;--j)
            min_v[j] = min_e = min(nums[j],min_e);
            
        int i = 0,j = size - 1;
        while(i < size && nums[i] >= max_v[i] && nums[i] <= min_v[i]) ++i;
        while(j > i && nums[j] <= min_v[j] && nums[j] >= max_v[j]) --j;
        
        return j - i + 1;
    }
};