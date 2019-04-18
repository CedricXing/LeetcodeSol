#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        if((m + n) % 2 == 1)
            return findKth(nums1,0,m-1,nums2,0,n-1,(m+n)/2);
        else{
            double a = findKth(nums1,0,m-1,nums2,0,n-1,(m+n)/2-1);
            double b = findKth(nums1,0,m-1,nums2,0,n-1,(m+n)/2);
            return (a+b)/2;
        }
    }

    double findKth(vector<int>& nums1,int start1,int end1,vector<int>& nums2,int start2,int end2,int k){
        if(start1>end1) return nums2[start2+k];
        else if(start2>end2)    return nums1[start1+k];
        int middle1 = (start1+end1)/2,middle2=(start2+end2)/2;
        if((end1-start1)%2==1)  middle1+=1;
        if((end2-start2)%2==1)  middle2+=1;
        if(middle1+middle2<k){
            if(nums1[middle1]>nums2[middle2])
                return findKth(nums1,start1,end1,nums2,middle2+1,end2,k-middle2-1);
            else
                return findKth(nums1,middle1+1,end1,nums2,start2,end2,k-middle1-1);
        }
        else{
            if(nums1[middle1]>nums2[middle2])
                return  findKth(nums1,start1,middle1-1,nums2,start2,end2,k);
            else
                return  findKth(nums1,start1,end1,nums2,start2,middle2-1,k); 
        }
    }
};

int main(){
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums2.push_back(3);
    nums2.push_back(4);
    Solution solution;
    solution.findMedianSortedArrays(nums1,nums2);
}