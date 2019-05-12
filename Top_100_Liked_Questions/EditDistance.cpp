#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /* Sol 0
    * Classical dynamic programming problem.
    * We focus on optimizing space use.
    * Stantard dp solution, O(n^2) space
    */
    int minDistance(string word1, string word2) {
        int m = word1.size(),n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int j = 0;j <= m;++j)
            dp[0][j] = j;
        for(int i = 0;i <= n;++i)
            dp[i][0] = i;
        for(int i = 1;i <= m;++i)
            for(int j = 1;j <= n;++j){
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
            }
        return dp[m][n];
    }

	/* Sol 1
	* Since dp[i] is only related to dp[i-1], we can use two vector
    * instead of O(n^2)   
	*/
    int minDistance1(string word1,string word2){
        int m = word1.size(),n = word2.size();
        vector<int> pre(n+1,0),cur(n+1,0);
        for(int j = 1;j <= n;++j)   pre[j] = j;
        for(int i = 1;i <= m;++i){ // start from 1, need to initialize the first element
            cur[0] = i; // initialize cur[0] 
            for(int j = 1;j <= n;++j){
                if(word1[i-1]==word2[j-1])  cur[j] = pre[j-1];
                else cur[j] = min(min(cur[j-1],pre[j]),pre[j-1])+1;
            }
            swap(cur,pre);
        }
        return pre[n];
    } 

	/* Sol 2
	* Further more, we can only use one vector
	*/
    int minDistance2(string word1,string word2){
        int m = word1.size(),n = word2.size(),pre;
        vector<int> cur(n+1,0);
        for(int j = 1;j <= n;++j) cur[j] = j;
        for(int i = 1;i <= m;++i){
            pre = i - 1; // initialize pre
            cur[0] = i; // initialize cur[0]
            for(int j = 1;j <= n;++j){
                int temp = cur[j];
                if(word1[i-1]==word2[j-1])  cur[j] = pre;
                else cur[j] = min(min(cur[j-1],cur[j]),pre)+1;
                pre = temp;
            }
        }
        return cur[n];
    }
};