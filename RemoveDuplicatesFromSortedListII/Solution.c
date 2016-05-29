/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* vHead = head;
    struct ListNode* vTail = NULL;
    struct ListNode* rHead = NULL;
    struct ListNode* rTail = NULL;
    bool uniq = false;
    while (vHead != NULL) {
        uniq = true;
        vTail = vHead;
        while (vTail->next != NULL) {
            if (vTail->next->val != vHead->val) {
                break;
            } else {
                uniq = false;
                vTail = vTail->next;
            }
        }
        if (uniq) {
            if (rHead == NULL) {
                rHead = vHead;
            } else {
                rTail->next = vHead;
            }
            rTail = vHead;
        }
        vHead = vTail->next;
    }
    if (rTail != NULL) rTail->next = NULL;
    return rHead;
}
