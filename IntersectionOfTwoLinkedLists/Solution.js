/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    if (headA === null || headB === null) return null;
    let tailA = headA;
    while (tailA.next !== null) tailA = tailA.next;
    tailA.next = headA;
    let fast = headB;
    let slow = headB;
    while (fast !== null && fast.next !== null) {
        fast = fast.next.next;
        slow = slow.next;
        if (fast == slow) break;
    }
    if (fast === null || fast.next === null) {
        tailA.next = null;
        return null;
    }
    fast = headB;
    while (slow != fast) {
        slow = slow.next;
        fast = fast.next;
    }
    tailA.next = null;
    return fast;
};