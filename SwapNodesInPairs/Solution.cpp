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
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* reverse = NULL;
        ListNode* node = NULL;
        while (head != NULL) {
            node = head;
            head = head->next;
            node->next = reverse;
            reverse = node;
        }
        return reverse;
    }

public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* reverseHead = NULL;
        ListNode* reverseTail = NULL;
        ListNode* subHead = NULL;
        ListNode* subTail = NULL;
        while (head != NULL) {
            subHead = head;
            if (head->next != NULL) {
                subTail = head->next;
                head = subTail->next;
                subTail->next = NULL;
            } else {
                head = head->next;
            }
            subHead = reverseList(subHead);
            if (reverseHead == NULL) {
                reverseHead = subHead;
                reverseTail = subHead;
            } else {
                reverseTail->next = subHead;
            }
            while (reverseTail->next != NULL) {
                reverseTail = reverseTail->next;
            }
        }
        return reverseHead;
    }
};
