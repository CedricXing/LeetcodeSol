#include <string>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int max_pos = str.length() - 1,left_ind = -1,right_ind = -1;
        for(int i = str.length() - 1;i >= 0;--i){
            if(str[i] > str[max_pos]){
                max_pos = i;
            }
            else if(str[i] < str[max_pos]){
                left_ind = i;
                right_ind = max_pos;
            }
        }
        swap(str[left_ind],str[right_ind]);
        return stoi(str);
    }
};