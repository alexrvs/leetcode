/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private TreeNode helper(ListNode head, ListNode end) {
        if (head == null) return null;
        ListNode fast = head;
        ListNode slow = head;
        while (fast != end && fast.next != end) {
            fast = fast.next.next;
            slow = slow.next;
        }
        TreeNode node = new TreeNode(slow.val);
        if (slow != head) {
            node.left = helper(head, slow);
        } else {
            node.left = null;
        }
        if (slow.next != end) {
            node.right = helper(slow.next, end);
        } else {
            node.right = null;
        }
        return node;
    }
    
    public TreeNode sortedListToBST(ListNode head) {
        return helper(head, null);
    }
}e