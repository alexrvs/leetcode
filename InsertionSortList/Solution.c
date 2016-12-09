/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL) return head;
    struct ListNode dummy;
    dummy.val = -1;
    dummy.next = head;
    struct ListNode* prev = head;
    struct ListNode* cur = prev->next;
    while (cur) {
        if (cur->val >= prev->val) {
            prev = cur;
            cur = cur->next;
        } else {
            struct ListNode* insertPrev = &dummy;
            struct ListNode* insertCur = dummy.next;
            while (insertCur->val < cur->val) {
                insertPrev = insertCur;
                insertCur = insertCur->next;
            }
            prev->next = cur->next;
            cur->next = insertCur;
            insertPrev->next = cur;
            cur = prev->next;
        }
    }
    return dummy.next;
}