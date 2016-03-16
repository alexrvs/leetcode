/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode * reverse = NULL;
        ListNode * node = head;
        while (node) {
            head = node->next;
            node->next = reverse;
            reverse = node;
            node = head;
        }
        return reverse;
    }

public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tmp = NULL;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        fast = reverseList(fast);
        while (fast != NULL) {
            slow = head->next;
            head->next = fast;
            fast = fast->next;
            head->next->next = slow;
            head = slow;
        }
        return;
    }
};
