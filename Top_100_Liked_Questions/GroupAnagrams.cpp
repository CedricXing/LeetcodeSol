#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > map;
        vector<vector<string> > result;
        for(auto str: strs){
            string t = str;
            sort(t.begin(),t.end());
            map[t].push_back(str);
        }
        for(auto e : map){
            result.push_back(move(e.second));
        }
        return result;
    }
};