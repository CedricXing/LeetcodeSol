#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 or matrix[0].size() == 0)
            return false;
        int lb = lower_bound(matrix,target);
        if(lb != matrix.size() && matrix[lb][0] == target) return true;
        if(lb == 0) return false;
        int row = lb - 1;
        lb = lower_bound(matrix[row],target);
        if(lb == matrix[row].size() or matrix[row][lb] != target) return false;
        else return true;
    }

    int lower_bound(vector<vector<int>> &matrix,int target){
        int left = 0, right = matrix.size();
        while(left < right){
            int middle = left + (right - left) / 2;
            if(matrix[middle][0] < target) left = middle + 1;
            else right = middle; 
        }
        return left;
    }

    int lower_bound(vector<int> &matrix,int target){
        int left = 0, right = matrix.size();
        while(left < right){
            int middle = left + (right - left) / 2;
            if(matrix[middle] < target) left = middle + 1;
            else right = middle; 
        }
        return left;
    }
};