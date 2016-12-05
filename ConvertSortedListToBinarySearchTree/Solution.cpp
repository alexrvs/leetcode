/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* helper(ListNode* head, ListNode* end) {
        if (head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        if (head != slow) {
            node->left = helper(head, slow);
        }
        if (slow->next != end) {
            node->right = helper(slow->next, end);
        }
        return node;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, NULL);
    }
};