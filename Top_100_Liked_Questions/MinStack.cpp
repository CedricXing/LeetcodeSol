#include <stack>
#include <climits>
using namespace std;

/* Sol
* Using two stacks, min_st to store the min values
*/ 
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> min_st;
    MinStack() {
    }
    
    void push(int x) {
        if(st.empty() || x <= min_st.top()){
            min_st.push(x);
        }
        st.push(x);
    }
    
    void pop() {
        if(st.top() == min_st.top()){
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/* Sol 1
* Only use one stack.
* When a new min_value occured, push the old min value.
* Very smart solution!!!
*/

class MinStack1 {
public:
    /** initialize your data structure here. */
    stack<int> st;
    int min;
    MinStack1() {
        min = INT_MAX;
    }
    
    void push(int x) {
        if(x <= min){
            st.push(min);
            min = x;
        }
        st.push(x);
    }
    
    void pop() {
        if(st.top() == min){
            st.pop();
            min = st.top();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};