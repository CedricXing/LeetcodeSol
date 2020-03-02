#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int u_find(vector<int> &arr,int i){
        if(i == arr[i]) return i;
        else return arr[i] = u_find(arr,arr[i]); // 这里要路径压缩一下，不然会超时
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> arr(s.length());
        for(int i = 0;i < s.length();++i)
            arr[i] = i;
        for(auto p : pairs){
            int root1 = u_find(arr,p[0]),root2 = u_find(arr,p[1]);
            if(root1 != root2) arr[root1] = root2;
        }
        vector<vector<int>> groups(s.length(),vector<int>());
        for(int i = 0;i < s.length();++i){
            int root = u_find(arr,i);
            groups[root].push_back(i);
        }
        string result(s.length(),' ');
        for(auto vec : groups){
            if(vec.empty()) continue;
            sort(vec.begin(),vec.end());
            string tmp;
            for(auto a : vec) tmp.push_back(s[a]);
            sort(tmp.begin(),tmp.end());
            for(int i = 0;i < vec.size();++i)
                result[vec[i]] = tmp[i];
        }
        return result;
    }
};