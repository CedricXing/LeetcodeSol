#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* 滑动窗口的思想。注意每次找到一个有效窗口时，任意从left开始，以right到len-1为末尾的都是有效的一个子串。
	*/
    int numberOfSubstrings(string s) {
        int len = s.length();
        vector<int> fre(3,0);
        int left = 0,right = 0;
        int result = 0;
        while(right < len){
            fre[s[right++] - 'a']++;
            while(left <= right && fre[0] > 0 && fre[1] > 0 && fre[2] > 0){
                result += (len - right + 1);
                fre[s[left++] - 'a']--;
            }
        }
        return result;
    }
};