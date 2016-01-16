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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oHead = head;
        if (oHead == NULL) {
            return head;
        }
        ListNode* eHead = head->next;
        if (eHead == NULL) {
            return head;
        }
        ListNode* cur = eHead->next;
        ListNode* oTail = oHead;
        ListNode* eTail = eHead;
        oTail->next = NULL;
        eTail->next = NULL;
        int cnt = 1;
        while (cur != NULL) {
            if (cnt % 2 == 1) {
                oTail->next = cur;
                oTail = cur;
                cur = cur->next;
                oTail->next = NULL;
            } else {
                eTail->next = cur;
                eTail = cur;
                cur = cur->next;
                eTail->next = NULL;
            }
            cnt++;
        }
        oTail->next = eHead;
        return oHead;
    }
};
