#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    vector<vector<int> > dp;
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > result;
        vector<string> vec;
        dp = vector<vector<int> >(s.length(),vector<int>(s.length(),-1));
        partition(s,0,s.length() - 1,result,vec);
        return result;
    }

    void partition(string &s,int left,int right,vector<vector<string> > &result,vector<string> &vec){
        if(left >= s.length()){
            result.push_back(vec);
            return;
        }
        for(int i = left;i <= right;i++){
            if(dp[left][i] == 0) continue;
            else if(dp[left][i] == 1 || (dp[left][i] == -1 && isPalindrome(s,left,i))){
                dp[left][i] = 1;
                vec.push_back(s.substr(left,i - left + 1));
                partition(s,i + 1,right,result,vec);
                vec.pop_back();
            }
            else{
                dp[left][i] = 0;
                continue;
            }
        }
    }

    bool isPalindrome(string &s,int left,int right){
        while(left <= right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    auto r = s.partition("aab");
    for(auto v : r){
        for(auto a : v) cout << a << " ";
        cout << endl;
    }
}