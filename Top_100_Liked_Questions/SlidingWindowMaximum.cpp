#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	/* Sol 0
	* In fact, the key point to solve the problem is to choose a correct data structure
    * to maintain the 'window'.
    * If we choose priority queue, red-black tree, we can get the average time complexity
    * of O(nlogk).
    * To achieve O(n) and to solve similar problems that need to maintain a 'window', 
    * we can try double ended queue.
    * In this problem, we use a deque to store the index and keep the elements sorted.
    * When it comes a new element of index i, we just need to compare it to the back end of the deque,
    * if nums[i] is larger, then deque.back() has no chance to be chosen in the future(because it has a smaller index than i),
    * we just need to pop it. The process continues until we encounter an element larger than nums[i], and 
    * we push the index i to the end of deque.
    * Now, we can also find that the front end element of the deque must be the oldest element, so if it is not in the window
    * any more (its index is smaller than i-k+1), we pop it.
    * The code is like the following. 
    * Since each element was pushed or poped once, so the average time complexity is O(n).
	*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size()==0 || k == 0) return result;
        deque<int> dq;
        for(int i = 0;i < nums.size();++i){
            if(!dq.empty() && dq.front() < i-k+1) // check if the first element is not in the window any more
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i]) 
                dq.pop_back();
            dq.push_back(i);
            if(i >= k-1) result.push_back(nums[dq.front()]);
        }        
        return result;
    }
};