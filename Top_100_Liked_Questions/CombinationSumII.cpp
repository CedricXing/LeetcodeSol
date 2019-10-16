#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Recursive solution.
	*/
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.empty() or target == 0) return result;
        sort(candidates.begin(),candidates.end(),[](int a,int b){return a>b;});//can also be done in ascending order
        vector<int> temp;
        combinationSum(candidates,target,0,result,temp); 
        return result;
    }

    void combinationSum(vector<int>& candidates,int target,int pos,vector<vector<int>> &result,vector<int> &temp){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        for(int i = pos;i < candidates.size();++i){
            if(i != pos && candidates[i] == candidates[i-1]) continue;//skip the duplicated combinations
            if(target-candidates[i] >= 0) {
                temp.push_back(candidates[i]);
                combinationSum(candidates,target-candidates[i],i+1,result,temp);
                temp.erase(temp.end()-1);
            }
        }
    }
};