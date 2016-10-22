/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
 
var reverseList = function(head, reverse) {
    var temp = null;
    while (head !== null) {
        temp = head.next;
        head.next = reverse;
        reverse = head;
        head = temp;
    }
    return reverse;
};
 
/**
 * @param {ListNode} head
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function(head, m, n) {
    var start = head;
    var end = head;
    var prev = null;
    var reverse = null;
    var i = 1;
    while (i < m || i < n) {
        if (i < m && start !== null) {
            prev = start;
            start = start.next;
        }
        if (i < n && end !== null) {
            end = end.next;
        }
        i++;
    }
    if (end === null) return head;
    reverse = end.next;
    end.next = null;
    start = reverseList(start, reverse);
    if (prev === null) head = start;
    else prev.next = start;
    return head;
};