#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	/* Sol 0
	* 和剑指上那道找每个元素后面比他大的第一个元素类似。
    * 用一个栈来存储。如果当天的温度比栈顶的高，那么就弹栈。
	*/
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> result(T.size(),0);
        for(int i = 0;i < T.size();++i){
            while(!st.empty() && T[i] > T[st.top()]){
                    result[st.top()] = i - st.top();
                    st.pop();
            }
            st.push(i);
        }
        return result;
    }
};