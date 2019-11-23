#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	/* Sol 0
	* Calculate the length first. O(n) time and O(1) space
	*/
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> result(k,nullptr);
        int len = 0;
        for(ListNode *p = root;p != nullptr;p=p->next) ++len;
        int m = len / k,n = len % k;
        ListNode *pre = nullptr;
        for(int i = 0;root != nullptr && i < k;++i){
            result[i] = root;
            for(int j = 0;j < m + (i < n);++j){
                pre = root;
                root = root->next;
            }
            pre->next = nullptr;
        }
        return result;        
    }
};