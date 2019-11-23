#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Firstly, we use a stack to store those elements that haven't found the next greater values;
    * Then, as it is a circular array, we should loop twice.
    * But we don't need to push elements again in the second loop.
	*/
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size,-1);
        stack<int> st;
        for(int i = 0;i < size * 2;++i){
            while(!st.empty() && nums[st.top()] < nums[i % size]){
                result[st.top()] = nums[i % size];
                st.pop();
            }
            if(i < size) st.push(i);
        }
        return result;
    }
};