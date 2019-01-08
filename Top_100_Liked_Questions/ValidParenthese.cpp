#include <string>
#include <stack>

using namespace std;

class Solution{
public:
    /* Sol
     * Obviously, we can use Stack to solve this problem.
     * The following code is my solution which beats 50% of C++ solutions.
    */
    bool isValid(string s){
        stack<char> st;
        for(int i = 0;i < s.size();++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if(st.empty())
                return false;
            else if(s[i] == ')'){
                if(st.top() != '(')
                    return false;
                else st.pop();
            }
            else if(s[i] == ']'){
                if(st.top() != '[')
                    return false;
                else st.pop();
            }
            else{
                if(st.top() != '{')
                    return false;
                else st.pop();
            }
        }
        return st.empty();        
    }

    /* Another cleaner C++ solution
     * Check by ASCII.
    */
    bool isValidASCII(string s) {
        // (40  )41  [91  ]93  {123 }125
        stack<char > m;
        for(auto ch:s){
            if(m.empty())
                m.push(ch);
            else{
                char t = m.top();
                if(ch-t==1 || ch-t==2)
                    m.pop();
                else{
                    m.push(ch);
                }
            }
        }
        return m.empty();
    }
};