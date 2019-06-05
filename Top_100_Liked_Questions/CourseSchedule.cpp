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
    bool canFinish(int numCourses,vector<vector<int>>& prerequisites) {
        stack<int> st;
        vector<int> arr(numCourses,0);
        unordered_map<int,vector<int>> map;
        for(auto p : prerequisites){
            arr[p[0]]++;
            if(map.count(p[1])==0)
                map[p[1]] = vector<int>();
            map[p[1]].push_back(p[0]);
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

    /* Sol 1
	* It's equivalent to finding if a cycle exists in a directed graph.
    * DFS or BFS can both detect if a cycle exists.
	*/
};