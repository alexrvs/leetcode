/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getLength(struct ListNode* head) {
    int length = 0;
    while (head != NULL) {
        head = head->next;
        length++;
    }
    return length;
}

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* reverse = NULL;
    struct ListNode* node = NULL;
    while (head != NULL) {
        node = head;
        head = head->next;
        node->next = reverse;
        reverse = node;
    }
    return reverse;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* rHead = NULL;
    struct ListNode* rTail = NULL;
    struct ListNode* sHead = NULL;
    struct ListNode* sTail = NULL;
    while (head != NULL) {
        sHead = head;
        sTail = head;
        int cnt = k;
        while (--cnt > 0 && sTail->next != NULL) {
            sTail = sTail->next;
        }
        if (cnt > 0) {
            break;
        }
        head = sTail->next;
        sTail->next = NULL;
        sHead = reverseList(sHead);
        if (rHead == NULL) {
            rHead = sHead;
            rTail = sHead;
        } else {
            rTail->next = sHead;
        }
        while (rTail->next != NULL) {
            rTail = rTail->next;
        }
    }
    if (rHead == NULL) return head;
    rTail->next = head;
    return rHead;
}
