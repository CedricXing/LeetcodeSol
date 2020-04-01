#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* 首先分别对开始时间和结束时间排序，然后用两个变量记录需要多少房间和已经完成的meeting。
    * 基本的思路就是如果当前的start[i]比正在进行的那个meeting结束时间要晚，那么就不需要新的room，否则需要新的room。
	*/
    int minMeetingRooms(vector<vector<int> >& intervals) {
        vector<int> start,end;
        for(auto v : intervals){
            start.push_back(v[0]);
            end.push_back(v[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int room_needed = 0,already_finished_meeting = 0;
        for(int i = 0;i < intervals.size();++i){
            if(start[i] < end[already_finished_meeting]) ++room_needed;
            else ++already_finished_meeting;
        }
        return room_needed;
    }
};