#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        auto cmp = [](vector<int> &v1,vector<int> &v2){return v1[0]<v2[0];};
        sort(intervals.begin(),intervals.end(),cmp);
        for(auto &v : intervals){
            if(result.empty() || result[result.size() - 1][1] < v[0]) result.push_back(v);
            else result[result.size() - 1][1] = max(v[1],result[result.size() - 1][1]);
        }
        return result;
    }
};
