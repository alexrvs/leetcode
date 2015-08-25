/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
  public ListNode detectCycle(ListNode head) {
    if (head == null) {
      return null;
    }
    ListNode fast = head;
    ListNode slow = head;
    do {
      if (fast != null) {
        fast = fast.next;
      }
      if (fast != null) {
        fast = fast.next;
      }
      if (fast == null) {
        return null;
      }
      slow = slow.next;
    } while (fast != slow);
    fast = head;
    while (fast != slow) {
      fast = fast.next;
      slow = slow.next;
    }
    return fast;
  }
}
