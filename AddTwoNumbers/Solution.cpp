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
    ListNode *addNode(ListNode * list, int i) {
        ListNode * newNode = new ListNode(i);
        if (list == NULL)
            list = newNode;
        else {
            ListNode * tmp = list;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
        return list;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int sum,num1,num2,in,digit;
        sum = num1 = num2 = in = digit = 0;
        ListNode * n1 = l1;
        ListNode * n2 = l2;
        ListNode * result = NULL;
        while (n1 || n2) {
            num1 = 0;
            num2 = 0;
            if (n1) {
                num1 = n1->val;
                n1 = n1->next;
            }
            if (n2) {
                num2 = n2->val;
                n2 = n2->next;
            }
            sum = num1 + num2 + in;
            digit = sum%10;
            in = sum/10;
            result = addNode(result, digit);
        }
        if (in != 0)
            result = addNode(result, in);
        return result;
    }
};
