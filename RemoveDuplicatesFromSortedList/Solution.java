/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return head;
        ListNode c = head;
        ListNode n = c.next;
        while (n != null) {
            if (c.val != n.val) {
                c.next = n;
                c = n;
            } else {
                c.next = null;
            }
            n = n.next;
        }
        return head;
    }
}
