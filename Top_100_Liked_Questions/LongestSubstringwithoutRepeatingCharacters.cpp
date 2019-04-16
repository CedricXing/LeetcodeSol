#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /*Sol 0
    * Use a vector as a hashmap.(The reason why size=256 is a char ranges from 0 - 255)
    */
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256,-1);
        int start=-1,maxLen=0;
        for(int i = 0;i < s.length();++i){
            if(dict[s[i]]>start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = maxLen<i-start?i-start:maxLen;
        }
        return maxLen;
    }
};