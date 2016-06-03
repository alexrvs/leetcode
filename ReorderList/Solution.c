/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode * reverse = NULL;
    struct ListNode * node = head;
    while (node) {
        head = node->next;
        node->next = reverse;
        reverse = node;
        node = head;
    }
    return reverse;
}

void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* tmp = NULL;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = slow->next;
    slow->next = NULL;
    fast = reverseList(fast);
    while (fast != NULL) {
        slow = head->next;
        head->next = fast;
        fast = fast->next;
        head->next->next = slow;
        head = slow;
    }
    return;
}
