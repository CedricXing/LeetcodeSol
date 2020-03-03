#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	/* Sol 0
	* 滑动窗口来解决，注意当且仅当滑动窗口的大小为P.size()的时候，才有可能满足。
    * 如何快速都判断当前滑动窗口是否满足条件是这类题都要考虑的问题，有些直接用计数器。但是这边用计数器会很复杂，而是用了两个vec，直接比较vec，类似于位向量。
	*/
    vector<int> findAnagrams(string s, string p) {
        vector<int> vec_p(26,0),vec_s(26,0),result;
        for(auto c : p) vec_p[c - 'a']++;
        int left = 0;
        for(int i = 0;i < s.length();++i){
            vec_s[s[i] - 'a']++;
            if(i - left == p.size() - 1){
                if(vec_p == vec_s) result.push_back(left);
                vec_s[s[left++] - 'a']--;
            }
        }
        return result;
    }
};