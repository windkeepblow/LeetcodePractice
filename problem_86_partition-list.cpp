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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1 = NULL;
        ListNode* h1 = NULL;
        ListNode* p2 = NULL;
        ListNode* h2 = NULL;

        ListNode* node = head;
        while (node) {
            if (node->val < x) {
                if (!p1) {
                    p1 = node;
                    h1 = node;
                } else {
                	p1->next = node;
                	p1 = p1->next;
                }
            } else {
                if (!p2) {
                	p2 = node;
                	h2 = node;
                } else {
                	p2->next = node;
                	p2 = p2->next;
                }   
            }
            node = node->next;
        }
        
        if (p1) p1->next = h2;
        if (p2) p2->next = NULL;

        if (h1) {
        	return h1;
        } else {
        	return h2;
        }
    }
};