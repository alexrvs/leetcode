/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
 public class Solution {
     public boolean isPalindrome(ListNode head) {
       if (head == null) {
         return true;
       }
       ListNode fast = head;
       ListNode slow = head;
       while (fast != null && fast.next != null) {
         fast = fast.next.next;
         slow = slow.next;
       }
       if (fast != null) {
         slow = slow.next;
       }
       ListNode tmp = null;
       ListNode reversed = null;
       while (slow != null) {
         tmp = slow;
         slow = slow.next;
         tmp.next = reversed;
         reversed = tmp;
       }
       slow = head;
       while (reversed != null) {
         if (reversed.val != slow.val) {
           return false;
         }
         reversed = reversed.next;
         slow = slow.next;
       }
       return true;
     }
 }
