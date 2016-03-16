/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private ListNode reverseList(ListNode head) {
        ListNode reverse = null;
        ListNode node = null;
        while (head != null) {
            node = head;
            head = head.next;
            node.next = reverse;
            reverse = node;
        }
        return reverse;
    }

    public void reorderList(ListNode head) {
        if (head == null || head.next == null) return;
        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        fast = slow.next;
        slow.next = null;
        fast = reverseList(fast);
        while (fast != null) {
            slow = head.next;
            head.next = fast;
            fast = fast.next;
            head.next.next = slow;
            head = slow;
        }
    }
}
