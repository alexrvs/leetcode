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
    ListNode *reverseList(ListNode *head, ListNode *reversed) {
        ListNode * tmp = NULL;
        while (head != NULL) {
            tmp = head->next;
            head->next = reversed;
            reversed = head;
            head = tmp;
        }
        return reversed;
    }
public:  
    ListNode *reverseBetween(ListNode *head, int m, int n) {  
        ListNode *prev = NULL;
        ListNode *start = head;
        ListNode *end = head;
        ListNode *reversed = NULL;
        while (--m > 0 && start != NULL) {
            prev = start;
            start = start->next;
        }
        while (--n > 0 && end != NULL) {
            end = end->next;
        }
        reversed = end->next;
        end->next = NULL;
        start = reverseList(start, reversed);
        if (prev != NULL) prev->next = start;
        else head = start;
        return head; 
    }  
};