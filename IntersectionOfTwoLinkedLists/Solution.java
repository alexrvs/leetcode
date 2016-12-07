/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        ListNode tailA = headA;
        while (tailA.next != null) tailA = tailA.next;
        tailA.next = headA;
        ListNode fast = headB;
        ListNode slow = headB;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) break;
        }
        if (fast == null || fast.next == null) {
            tailA.next = null;
            return null;
        }
        fast = headB;
        while (fast != slow) {
            fast = fast.next;
            slow = slow.next;
        }
        tailA.next = null;
        return slow;
    }
}