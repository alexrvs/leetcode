/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private ListNode reverseList(ListNode head, ListNode reversed) {
        while (head != null) {
            ListNode tmp = head.next;
            head.next = reversed;
            reversed = head;
            head = tmp;
        }
        return reversed;
    }
    
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode prev = null;
        ListNode start = head;
        ListNode end = head;
        ListNode reversed = null;
        while (--m > 0 && start != null) {
            prev = start;
            start = start.next;
        }
        while (--n > 0 && end != null) {
            end = end.next;
        }
        reversed = end.next;
        end.next = null;
        start = reverseList(start, reversed);
        if (prev != null) prev.next = start;
        else head = start;
        return head;
    }
}