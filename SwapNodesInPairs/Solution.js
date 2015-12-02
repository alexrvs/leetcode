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
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if (head === null || head.next === null) {
        return head;
    }
    var reverseHead = null;
    var reverseTail = null;
    var subHead = null;
    var subTail = null;
    while (head !== null) {
        subHead = head;
        if (head.next !== null) {
            subTail = head.next;
            head = subTail.next;
            subTail.next = null;
        } else {
            head = head.next;
        }
        subHead = reverseList(subHead);
        if (reverseHead === null) {
            reverseHead = subHead;
            reverseTail = subTail;
        } else {
            reverseTail.next = subHead;
        }
        while (reverseTail.next !== null) {
            reverseTail = reverseTail.next;
        }
    }
    return reverseHead;
};
