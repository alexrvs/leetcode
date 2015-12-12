/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode* node = NULL;
        RandomListNode* cur = NULL;
        cur = head;
        while (cur != NULL) {
            node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = head;
        while (cur != NULL) {
            node = cur->next;
            if (cur->random != NULL) {
                node->random = cur->random->next;
            }
            cur = node->next;
        }
        RandomListNode* res = NULL;
        RandomListNode* tail = NULL;
        cur = head;
        while (cur != NULL) {
            node = cur->next;
            if (res == NULL) {
                res = node;
            } else {
                tail->next = node;
            }
            tail = node;
            cur->next = node->next;
            cur = cur->next;
        }
        return res;
    }
};
