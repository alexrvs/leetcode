/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* lHead = NULL;
    struct ListNode* lTail = NULL;
    struct ListNode* sHead = NULL;
    struct ListNode* sTail = NULL;
    struct ListNode* cur = head;
    while (cur != NULL) {
        if (cur->val < x) {
            if (sHead == NULL) {
                sHead = cur;
            } else {
                sTail->next = cur;
            }
            sTail = cur;
            cur = cur->next;
            sTail->next = NULL;
        } else {
            if (lHead == NULL) {
                lHead = cur;
            } else {
                lTail->next = cur;
            }
            lTail = cur;
            cur = cur->next;
            lTail->next = NULL;
        }
    }
    if (sTail != NULL) {
        sTail->next = lHead;
        return sHead;
    }
    return lHead;
}