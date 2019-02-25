#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /*Sol 0
    * Moore Voting Algorithm
    * The key is majority element appears more than 1/2 times of all.
    * Space complexity O(1), time complexity O(n)
    */
    int majorityElement(vector<int>& nums) {
        int majority = nums[0],count = 1;
        for(int i = 1;i < nums.size();++i){
            if(count == 0){
                majority = nums[i];
                ++count;
            }
            else if(majority == nums[i]) ++count;
            else --count;
        }
        return majority;
    }

    /* Sol 1
    * Hash
    * Time complexity O(n),space complexity O(n)
    */
    int majorityElement1(vector<int>& nums){
        unordered_map<int,int> map;
        for(auto num : nums){
            if(++map[num] > nums.size() / 2)
                return num;
        }
        return nums[0];//control reaches non-void function, treat this as error
    }

    /* Sol 2
    * Random Algorithm
    * It's also fast to get the majority element.
    */
    int majorityElement2(vector<int>& nums){
        int len = nums.size();
        srand(time(NULL));
        while(true){
            int seed = nums[rand() % len];
            int count = 0;
            for(auto num : nums){
                if(num == seed) ++count;
            }
            if(count > len / 2) return seed;
        }
    }

    /* Sol 3
    * Sort
    * Easy to implement.
    * time complexity O(nlog(n)), space complexity O(1)
    */
};