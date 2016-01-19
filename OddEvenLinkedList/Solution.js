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
var oddEvenList = function(head) {
    var oHead = head;
    if (oHead === null) return head;
    var eHead = head.next;
    if (eHead === null) return head;
    var oTail = oHead;
    var eTail = eHead;
    var cur = eTail.next;
    oTail.next = null;
    eTail.next = null;
    var cnt = 1;
    while (cur !== null) {
        if (cnt % 2 == 1) {
            oTail.next = cur;
            cur = cur.next;
            oTail = oTail.next;
            oTail.next = null;
        } else {
            eTail.next = cur;
            cur = cur.next;
            eTail = eTail.next;
            eTail.next = null;
        }
        cnt++;
    }
    oTail.next = eHead;
    return oHead;
};