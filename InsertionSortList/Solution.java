/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null) return head;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = head;
        ListNode cur = prev.next;
        while (cur != null) {
            if (prev.val <= cur.val) {
                prev = cur;
                cur = cur.next;
            } else {
                prev.next = cur.next;
                ListNode insertNode = dummy.next;
                ListNode insertPrev = dummy;
                while (insertNode.val <= cur.val) {
                    insertPrev = insertNode;
                    insertNode = insertNode.next;
                }
                cur.next = insertNode;
                insertPrev.next = cur;
                cur = prev.next;
            }
        }
        return dummy.next;
    }
}
