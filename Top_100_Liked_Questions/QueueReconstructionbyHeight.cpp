#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* 首先考虑最小身高的人，假设他前面有i个比他高的，那么他在最后列表中的位置就是前面有i个空位或者大于等于他的位置。固定这个最矮的，再考虑其次矮的，依次确定所有人的位置。
	*/
    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
        vector<vector<int> > result(people.size(),vector<int>());
        sort(people.begin(),people.end(),[](vector<int> &vec1,vector<int> &vec2){return vec1[0] < vec2[0];});
        for(auto vec : people){
            int pos = -1;
            for(int i = 0;i < result.size();++i){
                if(result[i].size() == 0 || result[i][0] >= vec[0]){
                    ++pos;
                    if(pos == vec[1]){
                        result[i] = vec;
                        break;
                    }
                }     
            }
        }
        return result;
    }
};