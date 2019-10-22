#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* O(1) space complexity.
    * Use a row and a col to store information.
    * When finally setting zeros, process other rows and cols first.
	*/
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        bool first_row = false, first_col = false;
        for(int i = 0;i < m;++i)
            if(matrix[i][0] == 0){
                first_col = true;
                break;
            }
        for(int j = 0;j < n;++j){
            if(matrix[0][j] == 0){
                first_row = true;
                break;
            }
        }
        for(int i = 1;i < m;++i){
            for(int j = 1;j < n;++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1;i < m;++i)
            if(matrix[i][0] == 0)
                zero_row(matrix,i);
        for(int j = 1;j < n;++j)
            if(matrix[0][j] == 0)
                zero_col(matrix,j);
        if(first_row) zero_row(matrix,0);
        if(first_col) zero_col(matrix,0);
    }

    void zero_row(vector<vector<int>> &matrix,int row){
        for(int i = 0;i < matrix[0].size();++i)
            matrix[row][i] = 0;
    }

    void zero_col(vector<vector<int>> &matrix,int col){
        for(int i = 0;i < matrix.size();++i)
            matrix[i][col] = 0;
    }
};