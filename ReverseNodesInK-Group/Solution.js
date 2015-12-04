/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

var reverseList = function(head) {
    if (head === null || head.next === null) {
        return head;
    }
    var reverse = null;
    var node = null;
    while (head !== null) {
        node = head;
        head = head.next;
        node.next = reverse;
        reverse = node;
    }
    return reverse;
};

/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
    if (head === null || head.next === null) {
        return head;
    }
    var rHead = null;
    var rTail = null;
    var sHead = null;
    var sTail = null;
    var cnt = 0;
    while (head !== null) {
        sHead = head;
        sTail = head;
        cnt = k;
        while (--cnt > 0 && sTail.next !== null) {
            sTail = sTail.next;
        }
        if (cnt > 0) {
            break;
        }
        head = sTail.next;
        sTail.next = null;
        sHead = reverseList(sHead);
        if (rHead === null) {
            rHead = sHead;
            rTail = sHead;
        } else {
            rTail.next = sHead;
        }
        while (rTail.next !== null) {
            rTail = rTail.next;
        }
    }
    if (rHead === null) {
        return head;
    }
    rTail.next = head;
    return rHead;
};
