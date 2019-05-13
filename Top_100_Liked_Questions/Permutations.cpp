#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* This kind of problems can be solved using a similar recursive template.
    * Like Subset, Subset II, CombinationSum
	*/
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        permute(nums,result,temp);
        return result;        
    }

    void permute(vector<int> &nums,vector<vector<int>> &result,vector<int> &temp){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i = 0;i < nums.size();++i){
            if(nums[i] != INT_MIN){ // Here use INT_MIN to check whether nums[i] is in temp
                temp.push_back(nums[i]);// already(constant time). Basically, it's ok.
                nums[i] = INT_MIN;
                permute(nums,result,temp);
                nums[i] = temp.back();
                temp.erase(temp.end()-1);
            }
        }
    }
};