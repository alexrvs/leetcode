/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) return head;
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode* cur = &dummy;
    struct ListNode* tmp = NULL;
    while (cur->next != NULL) {
        if (cur->next->val == val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return dummy.next;
}
