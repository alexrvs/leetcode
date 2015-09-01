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
var reverseList = function(head) {
    var reverse = null;
    var node = head;
    while (node !== null) {
        head = node.next;
        node.next = reverse;
        reverse = node;
        node = head;
    }
    return reverse;
};
