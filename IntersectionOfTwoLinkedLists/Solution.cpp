/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode *tailA = headA;
        while (tailA->next != NULL) {
            tailA = tailA->next;
        }
        tailA->next = headA;
        ListNode *fast = headB;
        ListNode *slow = headB;
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
};