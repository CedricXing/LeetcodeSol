#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	/* Sol 0
	* The 2D dp array solution. O(mn) space and O(mn) time. Can be optimized to O(m) space.
	*/
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,0));
        dp[0][0] = 1;
        for(int i = 1;i <= p.size();++i){
            if(p[i-1] == '*') dp[0][i] = 1;
            else break;
        }
        for(int i = 0;i < s.size();++i){
            for(int j = 0;j < p.size();++j){
                if(p[j] == '?' || s[i] == p[j]) dp[i+1][j+1] = dp[i][j];
                else if(p[j] == '*') dp[i+1][j+1] = dp[i+1][j] || dp[i][j+1]; // as the end of current p is '*', so if dp[i][j+1] is ok, 
            }                                                                  // it will still be ok no matter how many letters are added after s
        }
        return dp[s.size()][p.size()];
    }
	/* Sol 1
	* Optimized to O(n) space.
	*/
    bool isMatch1(string s, string p) {
        vector<int> dp(p.size()+1,0);
        dp[0] = 1;
        for(int i = 1;i <= p.size();++i){
            if(p[i-1] == '*') dp[i] = 1;
            else break;
        }
        for(int i = 0;i < s.size();++i){
            int pre = dp[0];
            dp[0] = 0;
            for(int j = 0;j < p.size();++j){
                int temp = dp[j+1];
                if(p[j] == '?' || s[i] == p[j]) dp[j+1] = pre;
                else if(p[j] == '*') dp[j+1] = dp[j] || dp[j+1];
                else dp[j+1] = 0;
                pre = temp;
            }
        }
        return dp[p.size()];
    }
};

int main(){
    string s("acdcb");
    string p("a*c?b");
    Solution solution;
    solution.isMatch(s,p);
    solution.isMatch1(s,p);
    
}