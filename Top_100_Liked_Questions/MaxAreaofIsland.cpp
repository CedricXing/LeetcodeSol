#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i = 0;i < grid.size();++i){
            for(int j = 0;j < grid[0].size();++j){
                if(grid[i][j] == 1){
                    int temp_area = 0;
                    helper(grid,i,j,temp_area);
                    max_area = max(max_area,temp_area);
                }
            }
        }
        return max_area;
    }
    
    void helper(vector<vector<int>> &grid,int i,int j,int &area){
        area++;
        grid[i][j] = 0;
        if(i > 0 && grid[i - 1][j] == 1) helper(grid,i - 1,j,area);
        if(i < grid.size() - 1 && grid[i + 1][j] == 1) helper(grid,i + 1,j,area);
        if(j > 0 && grid[i][j - 1] == 1) helper(grid,i,j - 1,area);
        if(j < grid[0].size() - 1 && grid[i][j + 1] == 1) helper(grid,i,j + 1,area);
    }
};