#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	/* Sol 0
	* Traverse the string and use each character as the middle point（if even, use two characters as middle points.
    * Compute the longest palindrome substring and update dp[] at the same time.
	*/
    int minCut(string s) {
        if(s.length() <= 1) return 0;
        vector<int> dp(s.length(),0);
        for(int i = 0;i < s.length();++i)
            dp[i] = i;
        for(int mid = 0;mid < s.length();++mid){
            for(int left = mid,right = mid;left >= 0 && right < s.length() && s[left] == s[right];--left,++right){
                int newLeftStartCut = (left == 0) ? 0 : dp[left - 1] + 1;
                dp[right] = min(dp[right],newLeftStartCut);
            }
            for(int left = mid - 1,right = mid;left >= 0 && right < s.length() && s[left] == s[right];--left,++right){
                int newLeftStartCut = (left == 0) ? 0 : dp[left - 1] + 1;
                dp[right] = min(dp[right],newLeftStartCut);
            }
        }
        return dp[s.length() - 1];
    }
};

int main(){
    Solution s;
    cout << s.minCut("caabba") << endl;
}