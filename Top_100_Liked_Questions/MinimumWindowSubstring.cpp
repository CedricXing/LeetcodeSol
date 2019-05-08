#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /* Sol 0
    * The problem to find minimum or maximum substring that meets some 
    * restrictions can be solved use a map, two pointers, a counter.
    */
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c:t)   ++map[c];
        int left=0,right=0,counter=t.size(),minLen=INT_MAX,start=0;
        while(right < s.size()){
            if(map[s[right++]]-->0) --counter;
            while(counter==0){
                if(right-left<minLen) minLen = right-(start=left);
                if(map[s[left++]]++==0) ++counter;
            }
        }
        return (minLen==INT_MAX)?"":s.substr(start,minLen);
    }
};