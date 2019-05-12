class Solution {
public:
    /* Sol 0
    * F(n) = F(n-1) + F(n-2),F(1)=1,F(2)=2
    */
    int climbStairs(int n) {
        if(n <= 2)  return n;
        int pre = 1,current = 2;
        for(int i = 2;i < n;++i){
            int temp = current;
            current += pre;
            pre = temp;
        }
        return current;
    }
};