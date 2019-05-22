#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	/* Sol 0
	* O(n) time complexity
    * Obviously, if we pursue O(n) time complexity, we usually need to use a map.(Use space for time)
    * And the key point is to update the map in O(1). We can just maintain the boundary point of a
    * consecutive sequence. (It's a common trick in such kind of problems.)
	*/
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxCounter = 0;
        for(auto n : nums){
            if(map[n] == 0){
                int left = map[n-1],right = map[n+1];
                map[n] = left + right + 1;
                if(left != 0) map[n-left] = map[n];
                if(right != 0) map[n+right] = map[n];
                maxCounter = max(maxCounter,map[n]);
            }
        }
        return maxCounter;        
    }
};