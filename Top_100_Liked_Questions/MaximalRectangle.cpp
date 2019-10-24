#include <vector>
#include <initializer_list>
#include <iostream>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Can be solved based on Larget Rectangle in Histogram.
	*/
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<int> vec(matrix[0].size(),0);
        int result = 0;
        for(int i = 0;i < matrix.size();++i){
            for(int j = 0;j < matrix[0].size();++j){
                vec[j] = matrix[i][j] == '0' ? 0 : vec[j] + 1;
            }
            for(int p = 0;p < vec.size();++p)
                cout << vec[p] << ",";
            result = max(result,maximalRectangle(vec));
             cout << result << endl;
        }
        return result;
    }

    int maximalRectangle(vector<int> &vec){
        vector<int> leftMost(vec.size(),0), rightMost(vec.size(),vec.size() - 1);
        for(int i = 0,j = vec.size() - 1;i < vec.size();++i,--j){
            int p = i - 1;
            while(p >= 0 && vec[p] >= vec[i])
                p = leftMost[p] - 1;
            leftMost[i] = p + 1;
            int q = j + 1;
            while(q < vec.size() && vec[q] >= vec[j])
                q = rightMost[q] + 1;
            rightMost[j] = q - 1;
        }
        int result = 0;
        for(int i = 0;i < vec.size();++i){
            result = max(result,vec[i] * (rightMost[i] - leftMost[i] + 1));
        }
        return result;
    }
};