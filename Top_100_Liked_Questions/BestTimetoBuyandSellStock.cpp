#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if(prices.size() <= 1) return 0;
        int minP = prices[0];
        for(int i = 0;i < prices.size();++i){
            minP = min(minP,prices[i]);
            result = max(result,prices[i] - minP);
        }
        return result;
    }
};