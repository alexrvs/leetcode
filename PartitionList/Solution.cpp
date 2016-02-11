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
        ListNode* partition(ListNode* head, int x) {
            ListNode* lHead = NULL;
            ListNode* lTail = NULL;
            ListNode* sHead = NULL;
            ListNode* sTail = NULL;
            ListNode* cur = head;
            while (cur != NULL) {
                if (cur->val < x) {
                    if (sHead == NULL) {
                        sHead = cur;
                    } else {
                        sTail->next = cur;
                    }
                    sTail = cur;
                    cur = cur->next;
                    sTail->next = NULL;
                } else {
                    if (lHead == NULL) {
                        lHead = cur;
                    } else {
                        lTail->next = cur;
                    }
                    lTail = cur;
                    cur = cur->next;
                    lTail->next = NULL;
                }
            }
            if (sTail != NULL) {
                sTail->next = lHead;
                return sHead;
            }
            return lHead;
        }
};
