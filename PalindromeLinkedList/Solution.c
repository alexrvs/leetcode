/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL) {
        return true;
    }
    struct ListNode * fast = head;
    struct ListNode * slow = head;
    while (fast && fast->next) {
    fast = fast->next->next;
        slow = slow->next;
    }
    if (fast) {
        slow = slow->next;
    }
    struct ListNode * tmp = NULL;
    struct ListNode * reversed = NULL;
    while (slow) {
        tmp = slow;
        slow = slow->next;
        tmp->next = reversed;
        reversed = tmp;
    }
    slow = head;
    while (reversed) {
        if (reversed->val != slow->val) {
            return false;
        }
        reversed = reversed->next;
        slow = slow->next;
    }
    return true;
}
