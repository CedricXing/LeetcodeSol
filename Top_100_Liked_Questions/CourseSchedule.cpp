#include <vector>
#include <stack>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /* Sol 0
    * Detecting the cycle in a graph.
    * Using topology sort
    */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        stack<int> st;
        int *arr = new int[numCourses];
        memset(arr,0,numCourses*4);
        unordered_map<int,vector<int>> map;
        for(auto p : prerequisites){
            arr[p.second]++;
            if(map.count(p.first)==0)
                map[p.first] = vector<int>();
            map[p.first].push_back(p.second);
        }
        for(int i = 0;i < numCourses;++i){
            if(arr[i]==0)
                st.push(i);
        }
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            --numCourses;
            for(int c:map[temp]){
                if(--arr[c]==0)
                    st.push(c);
            }
        }
        if(numCourses != 0)
            return false;
        else return true;
    }
};