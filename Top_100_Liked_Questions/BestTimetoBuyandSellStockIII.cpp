#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* The following solution solves the more general question that we can do at most K transactions.
    * O(Kn) time complexity, O(Kn^2) space complexity that can be optimized to O(Kn).
    * We use dp[k][i] to indicate the result of until day i and at most k transactions can be done.
    * So dp[k][i] = max(dp[k][i-1],prices[i]-prices[j]+dp[k-1][j-1]) where 0<=j<=i-1.
    * Intuitively, we also need O(n) to compute dp[k][i], but we can record the current minimum value of (prices[i] - dp[k-1][i-1])
	*/
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int K = 2;
        vector<vector<int> > dp(K+1,vector<int>(prices.size(),0));
        for(int k = 1;k <= K;++k){
            int minimum = prices[0];
            for(int i = 1;i < prices.size();++i){
                minimum = min(minimum,prices[i] - dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1],prices[i] - minimum);
            }
        }
        return dp[K][prices.size()-1];
    }

	/* Sol 1
	* O(n) space complexity.
	*/
    int maxProfit1(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int K = 2;
        vector<int> dp(prices.size(),0);
        for(int k = 1;k <= K;++k){
            int minimum = prices[0];
            int pre = dp[0];
            for(int i = 1;i < prices.size();++i){
                int temp = dp[i];
                minimum = min(minimum,prices[i] - pre);
                dp[i] = max(dp[i-1],prices[i] - minimum);
                pre = temp;
            }
        }
        return dp[prices.size()-1];
    }
};