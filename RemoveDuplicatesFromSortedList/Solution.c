/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return head;
    struct ListNode * c = head;
    struct ListNode * n = c->next;
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
