#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        char *arr = new char[n*2+1];
        generateParenthesis(result,n,n,arr,0);
        return result;
    }

    void generateParenthesis(vector<string> &result,int left,int right,char *arr,int pos){
        if(left + right == 0){
            arr[pos] = '\0';
            string temp(arr);
            result.push_back(temp);
            return;
        }
        if(left > 0){
            arr[pos] = '(';
            generateParenthesis(result,left-1,right,arr,pos+1);
        }
        if(left < right){
            arr[pos] = ')';
            generateParenthesis(result,left,right-1,arr,pos+1); 
        }
    }
};