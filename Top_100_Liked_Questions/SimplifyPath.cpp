#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        path += "/";
        int pre = 0;
        for(int i = 0;i < path.length();++i){
            if(path[i] == '/'){
                if(i > pre + 1){
                    string tmp = path.substr(pre + 1,i - pre - 1);
                    if(tmp != ".." && tmp != ".") st.push(tmp);
                    else if(tmp == ".." && !st.empty()) st.pop();
                }
                pre = i;
            }
        }
        string result = "";
        while(!st.empty()){
            result = "/" + st.top() + result;
            st.pop();
        }
        return result == "" ? "/" : result;
    }
};