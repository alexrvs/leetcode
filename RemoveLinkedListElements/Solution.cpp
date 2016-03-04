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
        ListNode* removeElements(ListNode* head, int val) {
            ListNode dummy(0);
            ListNode *start = &dummy;
            start->next = head;
            while (start->next) {
                if (start->next->val == val) {
                    start->next = start->next->next;
                } else {
                    start = start->next;
                }
            }
            return dummy.next;
        }
};
