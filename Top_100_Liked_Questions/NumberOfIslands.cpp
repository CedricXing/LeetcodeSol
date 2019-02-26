#include <vector>
using namespace std;

class Solution {
public:
    /*Sol 0
    * If find an '1', make it and all '1' connected to it '0' using DFS or BFS.
    * My code can be optimized a lot to reduce the rebundant searching, but I choose to
    * keep it easy to understand.
    */
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i = 0;i < grid.size();++i)
            for(int j = 0;j < grid[0].size();++j){
                if(grid[i][j] == '1'){
                    ++result;
                    sink(grid,i,j);
                }
            }
        return result;
    }

    void sink(vector<vector<char>>& grid,int i,int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        sink(grid,i-1,j);
        sink(grid,i+1,j);
        sink(grid,i,j-1);
        sink(grid,i,j+1);
    }
};