/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null)
            return head;
        ListNode tail = head;
        int cnt = 1;
        while (tail.next != null) {
            tail = tail.next;
            cnt++;
        }
        tail.next = head;
        int step = cnt - k%cnt;
        while (step-- > 0) {
            head = head.next;
            tail = tail.next;
        }
        tail.next = null;
        return head;
    }
}
