/**
* Definition for singly-linked list.
* struct ListNode {
* int val;
* ListNode *next;
* ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = head;
        ListNode* cur = prev->next;
        while (cur) {
            if (cur->val >= prev->val) {
                prev = cur;
                cur = cur->next;
            } else {
                ListNode* insertPrev = &dummy;
                ListNode* insertCur = dummy.next;
                while (insertCur->val < cur->val) {
                    insertPrev = insertCur;
                    insertCur = insertCur->next;
                }
                prev->next = cur->next;
                cur->next = insertCur;
                insertPrev->next = cur;
                cur = prev->next;
            }
        }
        return dummy.next;
    }
};
