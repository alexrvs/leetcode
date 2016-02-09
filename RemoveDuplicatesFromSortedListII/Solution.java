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
        ListNode rHead = null;
        ListNode rTail = null;
        ListNode vHead = head;
        ListNode vTail = null;
        boolean uniq = false;
        while (vHead != null) {
            uniq = true;
            vTail = vHead;
            while (vTail.next != null) {
                if (vTail.next.val != vHead.val) {
                    break;
                } else {
                    uniq = false;
                    vTail = vTail.next;
                }
            }
            if (uniq) {
                if (rHead == null) {
                    rHead = vHead;
                } else {
                    rTail.next = vHead;
                }
                rTail = vHead;
            }
            vHead = vTail.next;
        }
        if (rTail != null) rTail.next = null;
        return rHead;
    }
}
