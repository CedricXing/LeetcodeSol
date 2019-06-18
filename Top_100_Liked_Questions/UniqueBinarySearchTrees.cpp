#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* It's easy to find the relationship between f_n and (f_n-1,f_n-2,...,f_1).
    * f(n) = f(0)*f(n-1)+f(1)*f(n-2)+...+f(n-1)*f(0)
	*/
    int numTrees(int n) {
        vector<int> dp(n+1,1);
        for(int i = 2;i < n+1;++i){
            int f_i = 0;
            for(int j = 0;j < i;++j)
                f_i += dp[j]*dp[i-1-j];
            dp[i] = f_i;
        }
        return dp[n];
    }
};