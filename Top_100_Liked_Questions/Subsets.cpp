#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Please refer to Permutations for the similar analysis.
	*/
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        subsets(nums,result,temp,0);      
        return result;
    }

    void subsets(vector<int> &nums,vector<vector<int>> &result,vector<int> &temp,int pos){
        result.push_back(temp);
        for(int i = pos;i < nums.size();++i){
            if(i != pos && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            subsets(nums,result,temp,i+1);
            temp.erase(temp.end()-1);
        }
    }
};