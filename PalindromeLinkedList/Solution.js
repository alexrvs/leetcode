/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    if ( head === null ) {
        return true;
    }
    fast = head;
    slow = head;
    while ( fast !== null && fast->next !== null ) {
        fast = fast.next.next;
        slow = slow.next;
    }
    if ( fast !== null ) {
        slow = slow.next;
    }
    tmp = null;
    reverse = null;
    while ( slow !== null ) {
        tmp = slow;
        slow = slow.next;
        tmp.next = reverse;
        reverse = tmp;
    }
    slow = head;
    while ( reverse !== null ) {
        if ( reverse.val !== slow.val ) {
            return false;
        }
        reverse = reverse.next;
        slow = slow.next;
    }
    return true;
};
