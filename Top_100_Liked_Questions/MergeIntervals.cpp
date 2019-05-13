#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Sort <intervals> first according to the start of each interval.
	*/
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty()) return result;
        auto cmp = [](const vector<int>& vec1,const vector<int>& vec2){
            return vec1[0] < vec2[0];// Pay attention to c++ 11's strict weak ordering,cannot make it <=
        };
        sort(intervals.begin(),intervals.end(),cmp);
        result.push_back(intervals[0]);
        for(int i = 1;i < intervals.size();++i){
            if(result.back()[1] >= intervals[i][0]) result.back()[1] = max(intervals[i][1],result.back()[1]);
            else result.push_back(intervals[i]);
        }
        return result;
    }
};