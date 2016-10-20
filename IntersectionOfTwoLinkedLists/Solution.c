/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    struct ListNode *tailA = headA;
    while (tailA->next != NULL) {
        tailA = tailA->next;
    }
    tailA->next = headA;
    struct ListNode *fast = headB;
    struct ListNode *slow = headB;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) break;
    }
    if (fast == NULL || fast->next == NULL) {
        tailA->next = NULL;
        return NULL;
    }
    fast = headB;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    tailA->next = NULL;
    return slow;
}