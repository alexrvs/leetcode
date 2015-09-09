/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    if (head === null) return head;
    var c = head;
    var n = c.next;
    while (n !== null) {
        if (c.val != n.val) {
            c.next = n;
            c = n;
        } else {
            c.next = null;
        }
        n = n.next;
    }
    return head;
};
