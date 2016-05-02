/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* reversed = NULL;
    struct ListNode* node = NULL;
    while (head != NULL) {
        node = head;
        head = head->next;
        node->next = reversed;
        reversed = node;
    }
    return reversed;
}
