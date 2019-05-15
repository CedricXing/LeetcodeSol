#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Brute force O(n^2) time, O(1) space
	*/
    int subarraySum(vector<int>& nums, int k) {
        int counter = 0,sum;
        for(int i = 0;i < nums.size();++i){
            sum = 0;
            for(int j = i;j < nums.size();++j){
                sum += nums[j];
                if(sum == k) ++counter;
            }
        }
        return counter;
    }

	/* Sol 1
	* Use a map to store preSum. O(n) space ,O(n) time.
	*/
    int subarraySum1(vector<int> &nums,int k){
        unordered_map<int,int> map;
        int counter = 0,sums = 0;
        map[0]++;//subarray may start at pos 0
        for(int i = 0;i < nums.size();++i){//The map[preSum] stores the number of preSum, 
            sums+=nums[i];                  //and we can count the subarrays ended in i
            counter+=map[sums-k];//there are map[sums-k] preSums each of which is (sums-k)
                                //so there are more map[sums-k] subarrays(start from corresponding positions to i)
            map[sums]++;
        }
        return counter;
    }
};