#include <iostream>
using namespace std;

class Solution {
public:
    /* Sol 0
    * Pay attention to the implemention of computing mod a negative number in C++.
    * If a < 0, a mod b = -(-a mod b)
    */
    int reverse(int x) {
        int result = 0;
        while(x != 0){
            if(result > INT_MAX / 10 || result < INT_MIN / 10)
                return 0;
            result = result*10 + x % 10;
            x=x/10;
        }
        return result;
    }
};