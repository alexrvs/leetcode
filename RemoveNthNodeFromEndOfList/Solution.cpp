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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode * tail = &dummy;
        ListNode * node = &dummy;
        while (n > 0) {
            tail = tail->next;
            n--;
        }
        while (tail->next != NULL) {
            node = node->next;
            tail = tail->next;
        }
        node->next = node->next->next;
        return dummy.next;
    }
};
