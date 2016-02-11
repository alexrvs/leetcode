/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
    var lHead = null;
    var lTail = null;
    var sHead = null;
    var sTail = null;
    var cur = head;
    while (cur !== null) {
        if (cur.val < x) {
            if (sHead === null) {
                sHead = cur;
            } else {
                sTail.next = cur;
            }
            sTail = cur;
            cur = cur.next;
            sTail.next = null;
        } else {
            if (lHead === null) {
                lHead = cur;
            } else {
                lTail.next = cur;
            }
            lTail = cur;
            cur = cur.next;
            lTail.next = null;
        }
    }
    if (sTail !== null) {
        sTail.next = lHead;
        return sHead;
    }
    return lHead;
};
