/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == NULL) return head;

        ListNode* p1 = head;
        while (p1->next != NULL) {
        	if (p1->val < p1->next->val) {
        		p1 = p1->next;
        	} else {
        		p1->next = p1->next->next;
        	}
        }

        return head;
    }
};