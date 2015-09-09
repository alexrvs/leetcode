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
        ListNode * c = head;
        ListNode * n = c->next;
        while (n != NULL) {
            if (n->val != c->val) {
                c->next = n;
                c = n;
            } else {
                c->next = NULL;
            }
            n = n->next;
        }
        return head;
    }
};
