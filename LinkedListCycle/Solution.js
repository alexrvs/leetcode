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
var hasCycle = function(head) {
  fast = head;
  slow = head;
  do {
    if ( fast !== null ) {
      fast = fast->next;
    }
    if ( fast !== null ) {
      fast = fast->next;
    }
    if ( fast === null ) {
      return false;
    }
    slow = slow->next;
  } while ( fast !== slow );
  return true;
};
