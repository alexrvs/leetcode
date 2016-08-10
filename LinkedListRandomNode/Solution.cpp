class Solution {
private:
    ListNode* m_head;
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        m_head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur = m_head;
        ListNode* res = NULL;
        for (int i = 1; cur != NULL; i++) {
            if (rand() % i == 0) res = cur;
            cur = cur->next;
        }
        return res->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
