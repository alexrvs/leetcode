/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    result = null;
    head   = null;
    c = 0;

    while (true) {
        num1 = 0;
        num2 = 0;
        if (l1 !== null) {
            num1 = l1.val;
            l1 = l1.next;
        }
        if (l2 !== null) {
            num2 = l2.val;
            l2 = l2.next;
        }
        sum = num1 + num2 + c;
        digit = sum % 10;
        c = Math.floor(sum / 10);
        node = new ListNode(digit);
        if (result === null) {
            result = node;
            head = node;
        } else {
            result.next = node;
            result = result.next;
        }
        if (l1 === null && l2 === null) break;
    }

    if (c !== 0) {
        node = new ListNode(c);
        result.next = node;
    }

    return head;
};
