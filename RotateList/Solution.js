/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
    if (head === null) return head;
    var tail = head;
    var cnt = 1;
    while (tail.next !== null) {
        tail = tail.next;
        cnt++;
    }
    tail.next = head;
    var step = cnt - k%cnt;
    while (step-- > 0) {
        head = head.next;
        tail = tail.next;
    }
    tail.next = null;
    return head;
};
