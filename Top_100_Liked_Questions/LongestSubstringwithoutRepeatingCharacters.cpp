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

    /* Sol 1
    * Use substring problem template
    */
    int lengthOfLongestSubstring1(string s){
        vector<int> dict(256,0);
        int left=0,right=0,start=0,maxLen=INT_MIN,counter=0;
        while(right < s.size()){
            if(dict[s[right++]]++>0) ++counter;
            while(counter>0) if(dict[s[left++]]-->1) --counter;
            maxLen = max(maxLen,right-left);
        }
        return (maxLen==INT_MIN)?0:maxLen;
    }
};