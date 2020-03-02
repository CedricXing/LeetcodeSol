#include <vector>
using namespace std;

class Solution {
public:
    int max_len;
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if(matrix.size() == 0) return 0;
        vector<vector<int> > dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        max_len = 0;
        for(int i = 0;i < matrix.size();++i){
            for(int j = 0;j < matrix[0].size();++j){
                if(dp[i][j] == -1){
                    helper(matrix,i,j,dp);
                }
            }
        }
        return max_len;
    }
    
    void helper(vector<vector<int> > &matrix,int i,int j,vector<vector<int> > &dp){
        dp[i][j] = 1;
        if(i > 0 && matrix[i][j] < matrix[i - 1][j]){
            if(dp[i - 1][j] == -1) helper(matrix,i - 1,j,dp);
            dp[i][j] = max(dp[i][j],dp[i - 1][j] + 1);
        }
        if(i < matrix.size() - 1 && matrix[i][j] < matrix[i + 1][j]){
            if(dp[i + 1][j] == -1) helper(matrix,i + 1,j,dp);
            dp[i][j] = max(dp[i][j],dp[i + 1][j] + 1);
        }
        if(j > 0 && matrix[i][j] < matrix[i][j - 1]){
            if(dp[i][j - 1] == -1) helper(matrix,i,j - 1,dp);
            dp[i][j] = max(dp[i][j],dp[i][j - 1] + 1);
        }
        if(j < matrix[0].size() - 1 && matrix[i][j] < matrix[i][j + 1]){
            if(dp[i][j + 1] == -1) helper(matrix,i,j + 1,dp);
            dp[i][j] = max(dp[i][j],dp[i][j + 1] + 1);
        }
        max_len = max(max_len,dp[i][j]);              
    }
};