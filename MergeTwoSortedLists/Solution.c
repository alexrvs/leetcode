/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *node1 = l1;
    struct ListNode *node2 = l2;
    struct ListNode *cur = NULL;
    struct ListNode *head = NULL;
    if (node1 == NULL)
        return l2;
    if (node2 == NULL)
        return l1;
    if (node1->val < node2->val) {
        cur = node1;
        node1 = node1->next;
    } else {
        cur = node2;
        node2 = node2->next;
    }
    head = cur;
    while(node1 != NULL && node2 != NULL) {
        if (node1->val < node2->val) {
            cur->next = node1;
            node1 = node1->next;
        } else {
            cur->next = node2;
            node2 = node2->next;
        }
        cur = cur->next;
    }
    if (node1 == NULL) {
        cur->next = node2;
    } else if (node2 == NULL) {
        cur->next = node1;
    }
    return head;
}
