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
    bool isPalindrome(ListNode* head) {
      if (head == NULL) {
        return true;
      }
      ListNode * fast = head;
      ListNode * slow = head;
      while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
      }
      if (fast) {
        slow = slow->next;
      }
      ListNode * tmp = NULL;
      ListNode * reversed = NULL;
      while (slow) {
        tmp = slow;
        slow = slow->next;
        tmp->next = reversed;
        reversed = tmp;
      }
      slow = head;
      while (reversed) {
        if (reversed->val != slow->val) {
          return false;
        }
        reversed = reversed->next;
        slow = slow->next;
      }
      return true;
    }
};
