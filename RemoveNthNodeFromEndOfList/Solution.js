/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    var dummy = new ListNode(-1);
    dummy.next = head;
    var tail = dummy;
    var node = dummy;
    while (n-- > 0) {
        tail = tail.next;
    }
    while (tail.next !== null) {
        node = node.next;
        tail = tail.next;
    }
    node.next = node.next.next;
    return dummy.next;
};
