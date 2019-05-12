#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /* Sol 0
    * Recursive way
    */
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0) return result;
        vector<string> digitChar = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        char temp_arr[digits.size() + 1];
        letterCombinations(result,temp_arr,digits,0,digitChar);
        return result;
    }

    void letterCombinations(vector<string> &result,char *temp_arr,string digits,int pos,vector<string> &digitChar){
        if(pos == digits.size()){
            temp_arr[pos] = '\0';
            result.push_back(temp_arr);
            return;
        }
        for(auto c : digitChar[digits[pos] - '0']){
            temp_arr[pos] = c;
            letterCombinations(result,temp_arr,digits,pos+1,digitChar);
        }
    }

    /* Sol 1
    * Iterative way use function swap
    */
    vector<string> letterCombinations1(string digits){
        vector<string> result;
        if(digits.size()==0)    return result;
        vector<string> digitChar = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        result.push_back(""); // add a seed
        for(auto d : digits){
            vector<string> tmp;
            for(auto c : digitChar[d-'0']){
                for(auto s : result)
                    tmp.push_back(s+c);
            }
            result.swap(tmp); // release memory
        }
        return result;
    }
};