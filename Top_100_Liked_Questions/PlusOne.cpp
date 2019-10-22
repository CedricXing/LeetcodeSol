#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1;i>=0;--i){
            digits[i] = ++digits[i] % 10;
            if(digits[i] != 0)
                return digits;
        }
        ++digits[0];
        digits.push_back(0);
        return digits;
    }
};