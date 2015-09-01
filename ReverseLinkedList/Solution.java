/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode reverse = null;
        ListNode node = head;
        while (node != null) {
            head = node.next;
            node.next = reverse;
            reverse = node;
            node = head;
        }
        return reverse;
    }
}
