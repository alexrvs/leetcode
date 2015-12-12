/**
 *  * Definition for singly-linked list with a random pointer.
 *   * function RandomListNode(label) {
 *    *     this.label = label;
 *     *     this.next = this.random = null;
 *      * }
 *       */

/**
 *  * @param {RandomListNode} head
 *   * @return {RandomListNode}
 *    */
var copyRandomList = function(head) {
    if (head === null) return null;
    var node = null;
    var cur  = head;
    while (cur !== null) {
        node = new RandomListNode(cur.label);
        node.next = cur.next;
        cur.next = node;
        cur = node.next;
    }
    cur = head;
    while (cur !== null) {
        node = cur.next;
        if (cur.random !== null) {
            node.random = cur.random.next;
        }
        cur = node.next;
    }
    var res = null;
    var tail = null;
    cur = head;
    while (cur !== null) {
        node = cur.next;
        if (res === null) {
            res = node;
        } else {
            tail.next = node;
        }
        tail = node;
        cur.next = node.next;
        cur = cur.next;
    }
    return res;
};
