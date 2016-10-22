/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head, struct ListNode* reversed) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head->next;
        head->next = reversed;
        reversed = head;
        head = temp;
    }
    return reversed;
}
 
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode* reversed = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* start = head;
    struct ListNode* end = head;
    while (--m > 0 && start != NULL) {
        prev = start;
        start = start->next;
    }
    while (--n > 0 && end != NULL) end = end->next;
    reversed = end->next;
    end->next = NULL;
    start = reverseList(start, reversed);
    if (prev == NULL) head = start;
    else prev->next = start;
    return head;
}