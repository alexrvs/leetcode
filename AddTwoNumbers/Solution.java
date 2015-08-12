/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = null;
        ListNode head   = null;
        int c = 0;

        do {
            int num1 = 0;
            int num2 = 0;
            if (l1 != null) {
                num1 = l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                num2 = l2.val;
                l2 = l2.next;
            }
            int sum = num1 + num2 + c;
            int digit = sum%10;
            c = sum/10;
            ListNode node = new ListNode(digit);
            if (result != null) {
                result.next = node;
                result = result.next;
            } else {
                result = node;
                head   = result;
            }
        } while ( l1 != null || l2 != null);

        if (c != 0) {
            ListNode node = new ListNode(c);
            result.next = node;
        }

        return head;
    }
}
