#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* 我平平无奇的解法...
	*/
    void rotate(vector<vector<int> >& matrix) {
        int counters = matrix.size() / 2,len = matrix.size();
        int i = 0;
        while(counters > 0){
            for(int j = i;j < i + len - 1;++j){
                int &first = matrix[i][j];
                int &second = matrix[j][i + len - 1];
                int &third = matrix[i + len - 1][2 * i + len - j - 1];
                int &fourth = matrix[2 * i + len - j - 1][i];
                int temp = first;
                first = fourth;
                fourth = third;
                third = second;
                second = temp;
            }
            ++i;
            len -= 2;
            --counters;
        }
    }
	/* Sol 1
	* 大佬们的解法..
    * see https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
	*/
    void rotate1(vector<vector<int> > &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
}
};