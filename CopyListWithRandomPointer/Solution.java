/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) return null;
        RandomListNode node = null;
        RandomListNode cur  = head;
        while (cur != null) {
            node = new RandomListNode(cur.label);
            node.next = cur.next;
            cur.next  = node;
            cur = node.next;
        }
        cur = head;
        while (cur != null) {
            node = cur.next;
            if (cur.random != null) {
                node.random = cur.random.next;
            }
            cur = node.next;
        }
        RandomListNode res  = null;
        RandomListNode tail = null;
        cur = head;
        while (cur != null) {
            node = cur.next;
            if (res == null) {
                res = node;
            } else {
                tail.next = node;
            }
            tail = node;
            cur.next = node.next;
            cur = cur.next;
        }
        return res;
    }
}
