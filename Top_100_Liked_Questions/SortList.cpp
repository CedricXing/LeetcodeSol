using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /* SOl 0
    * quickSort, swap values.
    * time complexity O(nlogn), space complexity O(logn)
    */
    ListNode* sortList(ListNode* head) {
        ListNode *end = head;
        quickSortList(head,nullptr);
        return head;
    }

    void quickSortList(ListNode *head,ListNode *end){
        if(head == end)
            return;
        int pivot = head->val;
        ListNode *p = head;
        ListNode *q = head;
        while(p != end){
            if(p->val < head->val){
                q = q->next;
                swap(p,q);
            }
            p = p -> next;
        }
        swap(q,head);
        quickSortList(head,q);
        quickSortList(q->next,end);
    }

    void swap(ListNode *a,ListNode *b){
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }

    /* Sol 1 bottom-up-merge-sort
    * time complexity O(nlogn), space complexity O(1)
    */
    ListNode *sortList1(ListNode *head) {
		if(!head || !(head->next)) return head;
		
		//get the linked list's length
		ListNode* cur = head;
		int length = 0;
		while(cur){
			length++;
			cur = cur->next;
		}
		ListNode dummy(0);
		dummy.next = head;
		ListNode *left, *right, *tail;
		for(int step = 1; step < length; step <<= 1){
			cur = dummy.next;
			tail = &dummy;
			while(cur){
				left = cur;
				right = split(left, step);
				cur = split(right,step);
				tail = merge(left, right, tail);
			}
		}
		return dummy.next;
	}
private:
	/**
	 * Divide the linked list into two lists,
     * while the first list contains first n ndoes
	 * return the second list's head
	 */
	ListNode* split(ListNode *head, int n){
		//if(!head) return NULL;
		for(int i = 1; head && i < n; i++) head = head->next;
		
		if(!head) return NULL;
		ListNode *second = head->next;
		head->next = NULL;
		return second;
	}
	/**
	  * merge the two sorted linked list l1 and l2,
	  * then append the merged sorted linked list to the node head
	  * return the tail of the merged sorted linked list
	 */
	ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
		ListNode *cur = head;
		while(l1 && l2){
			if(l1->val > l2->val){
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
			else{
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
			}
		}
		cur->next = (l1 ? l1 : l2);
		while(cur->next) cur = cur->next;
		return cur;
	}
};