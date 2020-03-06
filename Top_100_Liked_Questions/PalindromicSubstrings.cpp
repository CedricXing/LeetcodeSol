#include <string>
using namespace std;

class Solution {
public:
	/* Sol 0
	* O(n^2),直接把每个位置作为中心位置向两边扩展。要注意加上长度是偶数的情况。
	*/
    int countSubstrings(string s) {
        int result = 0;
        for(int i = 0;i < s.length();++i){
            result += helper(s,i,i);
            result += helper(s,i,i + 1);
        }
        return result;
    }
    
    int helper(string &s,int i,int j){
        int temp = 0;
        while(i >= 0 && j < s.length()){
            if(s[i--] != s[j++]) return temp;
            ++temp;
        }
        return temp;
    }
};