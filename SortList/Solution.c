/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* node1, struct ListNode* node2) {
    struct ListNode head;
    head.val = 0;
    head.next = NULL;
    struct ListNode* cur = &head;
    while (node1 != NULL && node2 != NULL) {
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
    } else {
        cur->next = node1;
    }
    return head.next;
}
 
struct ListNode* mergeSort(struct ListNode* node) {
    if (node == NULL || node->next == NULL) return node;
    struct ListNode* fast = node;
    struct ListNode* slow = node;
    struct ListNode* prev = node;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    return merge(mergeSort(node), mergeSort(slow));
}
 
struct ListNode* sortList(struct ListNode* head) {
    return mergeSort(head);
}