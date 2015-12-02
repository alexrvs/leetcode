/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private ListNode reverseList(ListNode node) {
        if (node == null || node.next == null) return node;
        ListNode reverse = null;
        ListNode tmp = null;
        while (node != null) {
            tmp = node;
            node = node.next;
            tmp.next = reverse;
            reverse = tmp;
        }
        return reverse;
    }

    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode subHead = null;
        ListNode subTail = null;
        ListNode reverseHead = null;
        ListNode reverseTail = null;
        ListNode node = head;
        while (node != null) {
            subHead = node;
            if (node.next != null) {
                subTail = node.next;
                node = subTail.next;
                subTail.next = null;
            } else {
                node = node.next;
            }
            subHead = reverseList(subHead);
            if (reverseHead == null) {
                reverseHead = subHead;
                reverseTail = subHead;
            } else {
                reverseTail.next = subHead;
            }
            while (reverseTail.next != null) reverseTail = reverseTail.next;
        }
        return reverseHead;
    }
}
