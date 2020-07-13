#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* This kind of problems can be solved using a similar recursive template.
    * Like Subset, Subset II, CombinationSum
	*/
    class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current,visited(nums.size(),0);
        if(nums.empty()) return result;
        helper(nums,result,current,visited);
        return result;
    }
    
    void helper(vector<int> &nums,vector<vector<int>> &result,vector<int> &current,vector<int> &visited){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }
        
        for(int i = 0;i < nums.size();++i){
            if(visited[i]) continue;
            visited[i] = 1;
            current.push_back(nums[i]);
            helper(nums,result,current,visited);
            visited[i] = 0;
            current.pop_back();
        }
    }
};
