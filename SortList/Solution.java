/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private ListNode merge(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        ListNode head = null;
        ListNode tail = null;
        ListNode tmp = null;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                tmp = l1;
                l1 = l1.next;
            } else {
                tmp = l2;
                l2 = l2.next;
            }
            if (head == null) {
                head = tmp;
            } else {
                tail.next = tmp;
            }
            tail = tmp;
        }
        if (l1 == null) tail.next = l2;
        if (l2 == null) tail.next = l1;
        return head;
    }
    private ListNode mergeSort(ListNode node) {
        if (node == null || node.next == null) return node;
        ListNode fast = node;
        ListNode slow = node;
        ListNode pre = null;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            pre = slow;
            slow = slow.next;
        }
        pre.next = null;
        return merge(mergeSort(node), mergeSort(slow));
    }
    public ListNode sortList(ListNode head) {
        return mergeSort(head);
    }
}
