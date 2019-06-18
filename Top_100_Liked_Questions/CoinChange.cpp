#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Dynamic programming.
    * O(n * amount) time complexity, O(amount) space complexity
	*/
    int coinChange(vector<int> &coins,int amount){
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        for(int i = 1;i <= amount;++i){
            for(int j = 0;j < coins.size();++j){
                if(i < coins[j]) continue;
                if(dp[i-coins[j]] != -1){ //if i-coins[j] can be made up
                    if(dp[i] == -1) dp[i] = dp[i-coins[j]] + 1; // dp[i] have not been made up yet
                    else dp[i] = min(dp[i],dp[i-coins[j]]+1); // check minimum number of coins
                }
            }
        }
        return dp[amount];
    }

    /* Sol 1
	* Greedy solution cannot be accepted.
    * Because greedy search always choose the largest coin, but it doesn't mean
    * the minimum number of coins used.
    * For example, coins= [13,6,1], amount=18
    * greedy : 13,1,1,1,1,1-->6
    * dp: 6,6,6->3
	*/
};
