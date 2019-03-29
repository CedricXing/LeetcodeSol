#include <vector>
using namespace std;

class Solution {
    vector<int> vec;
public:
    /* Sol 0
    * Brute Force
    */
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m <= 0)  return 0;
        int n = matrix[0].size();
        int maxLen = (m<n)?m:n;
        while(maxLen >= 1){
            for(int i = 0;i <= m-maxLen;++i){
                for(int j = 0;j <= n-maxLen;++j){
                    if(check(matrix,i,j,maxLen))
                        return maxLen*maxLen;
                    j = vec[1];
                }
            }
            --maxLen;
        }
        return 0;
    }
    bool check(vector<vector<char>>& matrix,int i,int j,int maxLen){
        vec.clear();
        for(int x = i;x < i + maxLen;++x){
            for(int y = j;y < j + maxLen;++y){
                if(matrix[x][y] != '1'){
                    vec.push_back(x);
                    vec.push_back(y);
                    return false;
                }
            }
        }
        return true;
    }

    /*Sol 1
    * Dynamic Programming
    * Let's use dp[i][j] to denote the maximum square can be formed till point (i,j)
    * So we have dp[i][j] = matrix[i][j] - '0' , for i == 0 or j == 0 or matrix[i][j] == '0'
    *                     min(dp[i][j-1],dp[i-1][j-1],dp[i-1][j]) + 1 , otherwise
    */

   int maximalSquare1(vector<vector<char>>& matrix) {
       if(matrix.empty()) return 0;
       int upper_left = 0, maxSize = 0;
       vector<int> vec(matrix.size(),0);
       for(int i = 0;i < matrix.size();++i){
           for(int j = 0;j < matrix[0].size();++j){
               int temp = vec[j];
               if(i == '0' || j == '0' || matrix[i][j] == '0')
                    vec[j] = matrix[i][j] - '0';
                else{
                    vec[j] = min(upper_left,min(vec[j],vec[j-1])) + 1;
                }
                upper_left = temp;
                maxSize = max(maxSize,vec[j]);
           }
       }
   }
};