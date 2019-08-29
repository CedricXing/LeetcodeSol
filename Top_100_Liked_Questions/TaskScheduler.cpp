#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
	/* Sol 0
	* We should obey the princple that
    * in each cycle, the task with larger numbers should be choosen first.
	*/
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> map;
        for(auto e : tasks){
            map[e]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto e : map){
            pq.push(make_pair(e.second,e.first));
        }
        int cycle = n + 1;
        int all_time = 0;
        while(!pq.empty()){
            int time_in_one_cycle = 0;
            vector<pair<int,char>> v;
            for(int i = 0;i < cycle;++i){
                if(!pq.empty()){
                    v.push_back(pq.top());
                    pq.pop();
                    time_in_one_cycle++;
                }
            }
            for(auto e : v){
                if(--e.first != 0){ // one kind of task isn't finished
                    pq.push(e);
                }
            }
            all_time += !pq.empty() ? cycle : time_in_one_cycle;
        } 
        return all_time;
    }

	/* Sol 1
	* We first find the task with maximum frequency (assume the frequence is max), then it needs at least (max - 1) * (n + 1) intervals as shown below.
    * Assume AAABCD,n=2:
    * than (3-1)* (2+1) will because at least A__A__
    * Afterwards, we count how many tasks are with frequency max. Just plus the number of tasks with max frequency. 
    * That because the last time of such task can only be scheduled after (max - 1) * (n - 1) intervals.
    * If the result is smaller than tasks.size(), it means there will not exist idle intervals. And in that case we just return tasks.size().
	*/
    int leastInterval1(vector<char>& tasks, int n){
        unordered_map<char,int> map;
        int count = 0;
        for(auto e : tasks){
            map[e]++;
            count = max(count,map[e]);
        }
        int all_time = (count - 1) * (n + 1);
        for(auto e : map){
            if(e.second == count)
                all_time++;
        }
        return max((int)all_time,tasks.size());
    }
};