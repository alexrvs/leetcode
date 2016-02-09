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
    var rHead = null;
    var rTail = null;
    var vHead = head;
    var vTail = null;
    var uniq = false;
    while (vHead !== null) {
        vTail = vHead;
        uniq = true;
        while (vTail.next !== null) {
            if (vTail.next.val != vHead.val) {
                break;
            } else {
                uniq = false;
                vTail = vTail.next;
            }
        }
        if (uniq === true) {
            if (rHead === null) {
                rHead = vHead;
            } else {
                rTail.next = vHead;
            }
            rTail = vHead;
        }
        vHead = vTail.next;
    }
    if (rTail !== null) rTail.next = null;
    return rHead;
};
