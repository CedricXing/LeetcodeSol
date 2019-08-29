#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1,1);
        if(n<=2)    return 1;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= i / 2;++j){
                dp[i] = max(dp[i],max(j*(i-j),j*dp[i-j]));
            }
        }
        return dp[n];                
    }
};