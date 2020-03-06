#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(auto n : nums) ++umap[n];
        auto cmp = [](pair<int,int> &p1,pair<int,int> &p2){return p2.second < p1.second;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(auto p : umap){
            if(pq.size() < k) pq.push(p);
            else if(p.second > pq.top().second){
                pq.pop();
                pq.push(p);
            }
        }
        vector<int> vec;
        while(!pq.empty()){
            vec.push_back(pq.top().first);
            pq.pop();
        }
        return vec;
    }
};