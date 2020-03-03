#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int size = matrix.size();
        if(size == 0) return false;
        int i = 0,j = matrix[0].size() - 1;
        while(i < size && j >= 0){
            if(target == matrix[i][j]) return true;
            else if(target > matrix[i][j]) ++i;
            else --j;
        }
        return false;
    }
};