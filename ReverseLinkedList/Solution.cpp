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
};
