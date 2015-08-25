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
var detectCycle = function(head) {
  var fast = head;
  var slow = head;
  do {
    if (fast !== null) {
      fast = fast.next;
    }
    if (fast !== null) {
      fast = fast.next;
    }
    if (fast === null) {
      return fast;
    }
    slow = slow.next;
  } while (fast != slow);
  fast = head;
  while (fast != slow) {
    fast = fast.next;
    slow = slow.next;
  }
  return fast;
};
