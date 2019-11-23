#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Recursive solution using DP.
	*/
    unordered_map<string,int> map;
    bool isScramble(string s1, string s2) {
        if(map.count(s1+s2)) return map[s1+s2];
        if(s1.size() != s2.size()) {
            return false;
        }
        vector<int> vec(26,0);
        for(int i = 0;i < s1.size();++i){
            vec[s1[i]-'a']++;
            vec[s2[i]-'a']--;
        }
        for(auto a : vec)
            if(a != 0) {
                map[s1+s2] = 0;
                return false;
            }
        if(s1==s2) {
            map[s1+s2] = 1;
            return true;
        }
        int len = s1.size();
        for(int i = 1;i < len;++i){
            bool result = (isScramble(s1.substr(0,i),s2.substr(0,i))&& isScramble(s1.substr(i,len-i),s2.substr(i,len-i))) || 
                            (isScramble(s1.substr(0,i),s2.substr(len-i,i)) && isScramble(s1.substr(i,len-i),s2.substr(0,len-i)));
            if(result) {
                map[s1+s2] = 1;
                return true;
            }
        }
        map[s1+s2] = 0;
        return false;
    }
    /* Sol 1
	* The bottom-up version DP, O(n^4) time complexity.
	*/
    bool isScramble1(string s1,string s2){
        if(s1.size() != s2.size()) return false;
        int len = s1.size();
        vector<vector<vector<int>>> dp(len+1,vector<vector<int>>(len,vector<int>(len,0)));
        for(int l = 1;l <= len;++l){
            for(int i = len - 1;i >= 0;--i){
                for(int j = len - 1;j >= 0;--j){
                    if(i + l > len || j + l > len) continue;
                    if(s1.substr(i,l)==s2.substr(j,l)) {
                        dp[l][i][j] = 1;
                        continue;
                    }
                    vector<int> vec(26,0);
                    for(int k = 0;k < l;++k){
                        vec[s1[i+k]-'a']--;
                        vec[s2[j+k]-'a']++;
                    }
                    for(auto a : vec){
                        if(a != 0){
                            dp[l][i][j] = 0;
                            continue;
                        }
                    }
                    for(int k = 1;k < l && !dp[l][i][j];++k){
                        dp[l][i][j] = (dp[k][i][j] && dp[l-k][i+k][j+k]) || (dp[k][i][j+l-k] && dp[l-k][i+k][j]);
                    }
                }
            }
        }
        return dp[len][0][0];
    }
};