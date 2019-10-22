#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* Use two pointers to indicate the current last position of zero and the first position of two.
    * We only need to adjust 0 to the former part of the array and adjust 2 to the latter part.
	*/
    void sortColors(vector<int>& nums) {
        int last_position_of_zero = -1, first_position_of_two = nums.size();
        for(int i = 0;i < first_position_of_two;++i){
            if(nums[i] == 0 && i != last_position_of_zero + 1)
                swap(nums[i--],nums[++last_position_of_zero]);
            else if(nums[i] == 2 && i != first_position_of_two - 1)
                swap(nums[i--],nums[--first_position_of_two]);
        }
    }

    /* Sol 1
	* Mind storming solution
	*/
    void sortColors2(vector<int> &nums){
        int pos_0 = -1, pos_1 = -1, pos_2 = -1;
        for(int i = 0;i < nums.size();++i){
            if(nums[i] == 0){
                nums[++pos_2] = 2;
                nums[++pos_1] = 1;
                nums[++pos_0] = 0;
            }
            else if(nums[i] == 1){
                nums[++pos_2] = 2;
                nums[++pos_1] = 1;
            }
            else{
                nums[++pos_2] = 2;
            }
        }
    }
};