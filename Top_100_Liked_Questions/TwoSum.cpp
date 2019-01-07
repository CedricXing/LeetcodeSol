class Solution {
public:
    /* Sol 0
     * Brute force O(n^2)
     * Two loops
    */
    
    /* Sol 1
     * Sort in O(nlogn)
     * For each nums[i], find target - nums[i] by binary search --> O(nlogn)
     * Totally, O(nlogn), better than Brute force
    */
  
    /* Sol 2
     * Use hash to find target - nums[i] in O(1)
     * Conventionally, we need traverse the list twice, one for hashing and the other for searching.
     * TRICK: hash target - nums[i] instead. So, if nums[i] is already in map, it means we find the result. Only traverse the list once.
     * Final Code:
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> map;
        for(int i = 0;i < nums.size();++i){
            //target - nums[i] did not appear yet
            if(map.find(nums[i]) == map.end()){
                map[target - nums[i]] = i;
            }
            else{//find the solution
                result.push_back(map[nums[i]]);
                result.push_back(i);
                break;//according to the assumpiton
            }
        }
        return result;
    }
};
