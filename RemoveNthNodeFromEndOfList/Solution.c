/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.val = -1;
    dummy.next = head;
    struct ListNode * tail = &dummy;
    struct ListNode * node = &dummy;
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
