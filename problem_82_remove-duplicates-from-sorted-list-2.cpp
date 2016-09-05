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
        if (!head) return head;

        ListNode* last_node = NULL;
        ListNode* p1 = head;
        ListNode* real_head = NULL;

        while (p1 && p1->next) {
            if (p1->val != p1->next->val) {
            	if (!real_head) real_head = p1;
            	if (!last_node) {
            	    last_node = p1;
                } else {
            	    last_node->next = p1;
            	   	last_node = last_node->next;
            	 }
            	p1 = p1->next;
            } else {
                ListNode* p2 = p1->next;
                while (p2 && p2->val == p1->val) p2 = p2->next;                    
                p1 = p2;
                if ((!p1 || !p1->next) && last_node) last_node->next = p1;
            }
        }
        
        if (!real_head && p1) real_head = p1;
        
        return real_head;
    }
};