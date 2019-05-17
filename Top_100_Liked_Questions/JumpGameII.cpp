#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* The variant of greedy.
	*/
    int jump(vector<int>& nums) {
        int farestReach = 0, end = 0,counter = 0;
        for(int i = 0;i < nums.size();++i){
            farestReach = max(farestReach,i + nums[i]);
            if(i == end && i != nums.size() - 1){//only increment counter
                ++counter;        // when reach the current end and the end is not the destination
                end = farestReach;
            }
        }
        return counter;
    }
};