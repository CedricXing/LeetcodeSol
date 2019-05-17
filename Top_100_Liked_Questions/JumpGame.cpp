#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Greedy.
    * Record the farest position can be reached up to now.
    * If i > reachFarest, it means we cannot jump to the rightmost position.
	*/
    bool canJump(vector<int>& nums) {
        int reachFarest = 0;
        for(int i = 0;i < nums.size();++i){
            if(i > reachFarest)    return false;
            reachFarest = max(reachFarest,i + nums[i]);
        }
        return true;
    }
};