/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

var merge = function(l1, l2) {
    if (l1 === null) return l2;
    if (l2 === null) return l1;
    var head = null;
    var tail = null;
    var temp = null;
    while (l1 !== null && l2 !== null) {
        if (l1.val < l2.val) {
            temp = l1;
            l1 = l1.next;
        } else {
            temp = l2;
            l2 = l2.next;
        }
        if (head === null) {
            head = temp;
        } else {
            tail.next = temp;
        }
        tail = temp;
    }
    if (l1 === null) tail.next = l2;
    if (l2 === null) tail.next = l1;
    return head;
};

var mergeSort = function(node) {
    if (node === null || node.next === null) return node;
    var fast = node;
    var slow = node;
    var prev = null;
    while (fast !== null && fast.next !== null) {
        fast = fast.next.next;
        prev = slow;
        slow = slow.next;
    }
    prev.next = null;
    return merge(mergeSort(node), mergeSort(slow));
};

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var sortList = function(head) {
    return mergeSort(head);
};
