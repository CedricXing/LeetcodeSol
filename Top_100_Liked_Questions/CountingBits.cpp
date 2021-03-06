#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1,0);
        for(int i = 1;i <= num;++i)
            result[i] = result[i & (i - 1)] + 1;
        return result;
    }
};