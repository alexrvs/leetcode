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

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* node = NULL;
    struct ListNode* reversedHead = NULL;
    struct ListNode* reversedTail = NULL;
    while (head != NULL) {
        node = head;
        if (node->next != NULL) {
            head = node->next->next;
            node->next->next = NULL;
            node = reverseList(node);
        } else {
            head = NULL;
        }
        if (reversedHead == NULL) {
            reversedHead = node;
            reversedTail = node;
        } else {
            reversedTail->next = node;
        }
        while (reversedTail->next != NULL) {
            reversedTail = reversedTail->next;
        }
    }
    return reversedHead;
}
