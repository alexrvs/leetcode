/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) return head;
        ListNode oHead = head;
        ListNode eHead = head.next;
        if (eHead == null) return head;
        int cnt = 1;
        ListNode cur = eHead.next;
        ListNode oTail = oHead;
        ListNode eTail = eHead;
        oTail.next = null;
        eTail.next = null;
        while (cur != null) {
            if (cnt % 2 == 1) {
                oTail.next = cur;
                cur = cur.next;
                oTail = oTail.next;
                oTail.next = null;
            } else {
                eTail.next = cur;
                cur = cur.next;
                eTail = eTail.next;
                eTail.next = null;
            }
            cnt++;
        }
        oTail.next = eHead;
        return oHead;
    }
}
