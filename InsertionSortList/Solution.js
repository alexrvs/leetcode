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
var insertionSortList = function(head) {
    if (head === null) return head;
    var dummy = new ListNode(-1);
    dummy.next = head;
    var prev = head;
    var cur = head.next;
    while (cur !== null) {
        if (prev.val <= cur.val) {
            prev = cur;
            cur = cur.next;
        } else {
            var insertPrev = dummy;
            var insertNode = dummy.next;
            prev.next = cur.next;
            while (insertNode.val <= cur.val) {
                insertPrev = insertNode;
                insertNode = insertNode.next;
            }
            cur.next = insertNode;
            insertPrev.next = cur;
            cur = prev.next;
        }
    }
    return dummy.next;
};
