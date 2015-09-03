/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode tail = dummy;
        ListNode node = dummy;
        while (n-- > 0) {
            tail = tail.next;
        }
        while (tail.next != null) {
            node = node.next;
            tail = tail.next;
        }
        node.next = node.next.next;
        return dummy.next;
    }
}
