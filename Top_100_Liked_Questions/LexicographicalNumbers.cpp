#include <vector>
using namespace std;

class Solution {
public:
	/* Sol 0
	* We consider the dictionary order and we can conclude as follows
    * 1.for a number a, its next number is a * 10 (add a '0')
    * 2. if a * 10 > n, then let a plus 1, but we should notice the next number after 19 will not be 20, but 2
    * 3. therefore, we should remove all 0 after we puls 1.
	*/
    vector<int> lexicalOrder(int n) {
        vector<int> result(n,0);
        int current = 1;
        for(int i = 0;i < n;++i){
            result[i] = current;
            if(current * 10 <= n) current *= 10;
            else{
                if(current >= n) current /= 10;
                ++current;
                while(current % 10 == 0){current /= 10;}
            }
        }
        return result;
    }
};