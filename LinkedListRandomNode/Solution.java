public class Solution {
    private ListNode head;
    private int len;

    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        this.head = head;
        this.len = 0;
        while (head != null) {
            head = head.next;
            this.len++;
        }
    }

    /** Returns a random node's value. */
    public int getRandom() {
        int step = new Random().nextInt(len);
        ListNode cur = this.head;
        while (step-- != 0) {
            cur = cur.next;
        }
        return cur.val;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
