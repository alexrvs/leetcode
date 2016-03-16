/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
var reverse = function(head) {
    var node = null;
    var reverse = null;
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
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    if (head === null || head.next === null) return;
    var slow = head;
    var fast = head;
    while (fast.next !== null && fast.next.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    fast = slow.next;
    slow.next = null;
    fast = reverse(fast);
    slow = head;
    while (fast !== null) {
        tmp = slow.next;
        slow.next = fast;
        fast = fast.next;
        slow.next.next = tmp;
        slow = tmp;
    }
};
