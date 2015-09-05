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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * tail = head;
        if (head == NULL) return head;
        int cnt = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            cnt++;
        }
        tail->next = head;
        int step = cnt - k%cnt;
        while (step-- > 0) {
            head = head->next;
            tail = tail->next;
        }
        tail->next = NULL;
        return head;
    }
};
