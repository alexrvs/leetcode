/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* oHead = head;
    if (oHead == NULL) {
        return head;
    }
    struct ListNode* eHead = head->next;
    if (eHead == NULL) {
        return head;
    }
    struct ListNode* cur = eHead->next;
    struct ListNode* oTail = oHead;
    struct ListNode* eTail = eHead;
    oTail->next = NULL;
    eTail->next = NULL;
    int cnt = 1;
    while (cur != NULL) {
        if (cnt % 2 == 1) {
            oTail->next = cur;
            oTail = cur;
            cur = cur->next;
            oTail->next = NULL;
        } else {
            eTail->next = cur;
            eTail = cur;
            cur = cur->next;
            eTail->next = NULL;
        }
        cnt++;
    }
    oTail->next = eHead;
    return oHead;
}
