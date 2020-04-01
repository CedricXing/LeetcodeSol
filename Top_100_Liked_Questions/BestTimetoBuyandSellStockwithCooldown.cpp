#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* 用buy和sell两个数组来记录第i天买和第i天卖的最大收益。
	*/
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<int> buy(prices.size()),sell(prices.size());
        buy[0] = -prices[0];
        int result = 0;
        for(int i = 1;i < prices.size();++i){
            sell[i] = max(sell[i - 1] - prices[i - 1] + prices[i],buy[i - 1] + prices[i]);
            result = max(sell[i],result);
            if(i == 1) buy[i] = -prices[1];
            else buy[i] = max(sell[i - 2] - prices[i],buy[i - 1] + prices[i - 1] - prices[i]);
        }
        return result;
    }
};