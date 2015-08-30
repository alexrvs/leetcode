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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        ListNode *cur = NULL;
        ListNode *head = NULL;
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
};
