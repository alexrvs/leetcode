/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode lHead = null;
        ListNode lTail = null;
        ListNode sHead = null;
        ListNode sTail = null;
        ListNode cur = head;
        while (cur != null) {
            if (cur.val < x) {
                if (sHead == null) {
                    sHead = cur;
                } else {
                    sTail.next = cur;
                }
                sTail = cur;
                cur = cur.next;
                sTail.next = null;
            } else {
                if (lHead == null) {
                    lHead = cur;
                } else {
                    lTail.next = cur;
                }
                lTail = cur;
                cur = cur.next;
                lTail.next = null;
            }
        }
        if (sTail != null) {
            sTail.next = lHead;
            return sHead;
        }
        return lHead;
    }
}
