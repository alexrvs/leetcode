/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private int getLength(ListNode head) {
        int length = 0;
        while (head != null) {
            head = head.next;
            length++;
        }
        return length;
    }

    private ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
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

    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        int l = getLength(head);
        if (l < k) {
            return head;
        }
        ListNode rHead = null;
        ListNode rTail = null;
        ListNode sHead = null;
        ListNode sTail = null;
        while (head != null) {
            sHead = head;
            sTail = head;
            int cnt = k;
            while (--cnt > 0 && sTail.next != null) {
                sTail = sTail.next;
            }
            if (cnt > 0) {
                break;
            }
            head = sTail.next;
            sTail.next = null;
            sHead = reverseList(sHead);
            if (rHead == null) {
                rHead = sHead;
                rTail = sHead;
            } else {
                rTail.next = sHead;
            }
            while (rTail.next != null) {
                rTail = rTail.next;
            }
        }
        if (rTail != null) {
            rTail.next = head;
        }
        return rHead;
    }
}
