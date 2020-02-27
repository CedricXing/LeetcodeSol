#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Push the position of the character instead of the character itself.
    * If you push the charachter, it's a little difficult to decide when to update the
    * maxLen (because you cannot tell the current string is legal or not). But, if you 
    * record the position, you can update the maxLen whenever it comes a new pair.
	*/
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLen = 0;
        for(int i = 0;i < s.length();++i){
            if(st.top()!=-1 && s[st.top()]=='(' && s[i]==')'){
                st.pop();
                maxLen = max(maxLen,i-st.top());
            }
            else st.push(i);
        }
        return maxLen;
    }
};