#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	/* Sol 0
	* With clear logic.
    * Use (m * n) space.
	*/
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        if(dungeon.empty() || dungeon[0].empty()) return 0;
        int m = dungeon.size(),n = dungeon[0].size();
        vector<vector<int> > dp(m,vector<int>(n,1));
        for(int i = m -1;i >= 0;--i){
            for(int j = n - 1;j >= 0;--j){
                int min_ = 0;
                if(i == m - 1 && j == n - 1){
                    if(dungeon[i][j] <= 0) dp[i][j] = 1 - dungeon[i][j];
                    continue;
                }
                else if(i != m - 1 && j == n - 1)   min_ = dp[i + 1][j];
                else if(i == m - 1 && j != n - 1)   min_ = dp[i][j + 1];
                else min_ = min(dp[i + 1][j],dp[i][j + 1]);
                if(min_ > 0){
                    if(dungeon[i][j] < 0) dp[i][j] = min_ - dungeon[i][j];
                    else if(dungeon[i][j] < min_) dp[i][j] = min_ - dungeon[i][j];
                }
                else if(dungeon[i][j] <= 0) dp[i][j] = 1 - dungeon[i][j];
            }
        }
        return dp[0][0];
    }

	/* Sol 1
	* Use (m + 1) * (n + 1) space to make the solution much easier
	*/
    int calculateMinimumHP1(vector<vector<int> >& dungeon) {
        if(dungeon.empty() || dungeon[0].empty()) return 0;
        int m = dungeon.size(),n = dungeon[0].size();
        vector<vector<int> > dp(m + 1,vector<int>(n + 1,INT32_MAX));
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;
        for(int i = m -1;i >= 0;--i){
            for(int j = n - 1;j >= 0;--j){
                int need = min(dp[i + 1][j],dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = (need <= 0) ? 1 : need;
            }
        }
        return dp[0][0];
    }

};

int main(){
    Solution s;
    vector<vector<int> > vec;
    vector<int> vec1{-2,-3,3};
    vector<int> vec2{-5,-10,1};
    vector<int> vec3{10,30,-5};
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);

    cout << s.calculateMinimumHP(vec) << endl;
}