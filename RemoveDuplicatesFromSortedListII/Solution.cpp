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
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* vHead = head;
            ListNode* vTail = NULL;
            ListNode* rHead = NULL;
            ListNode* rTail = NULL;
            bool uniq = false;
            while (vHead != NULL) {
                uniq = true;
                vTail = vHead;
                while (vTail->next != NULL) {
                    if (vTail->next->val != vHead->val) {
                        break;
                    } else {
                        uniq = false;
                        vTail = vTail->next;
                    }
                }
                if (uniq) {
                    cout << vHead->val << endl;
                    if (rHead == NULL) {
                        rHead = vHead;
                    } else {
                        rTail->next = vHead;
                    }
                    rTail = vHead;
                }
                vHead = vTail->next;
            }
            if (rTail != NULL) rTail->next = NULL;
            return rHead;
        }
};
