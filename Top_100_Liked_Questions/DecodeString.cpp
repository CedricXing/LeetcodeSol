#include <string>
using namespace std;

class Solution {
public:
	/* Sol 0
	* 递归，如果遇到数字，就递归处理下一个字符串，遇到]就返回
	*/
    string decodeString(string s) {
        int pos = 0;
        return decodeString(s,pos);
    }
    
    string decodeString(string &s,int &pos){
        string str;
        while(pos < s.length() && s[pos] != ']'){
            if(!digit(s[pos])) str.push_back(s[pos++]);
            else{
                int n = 0;
                while(digit(s[pos])){
                    n = n * 10 + s[pos++] - '0';
                }
                ++pos; // [
                string tmp = decodeString(s,pos);
                ++pos; // ]
                while(n > 0){
                    str += tmp;
                    --n;
                }
            }
        }
        return str;
    }
    
    bool digit(char c){
        if(c >= '0' && c <= '9') return true;
        else return false;
    }
};