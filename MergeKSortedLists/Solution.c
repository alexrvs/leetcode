/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct Node {
    struct ListNode* listNode;
    struct Node* next;
};

struct Node* createNode(struct ListNode* listNode) {
    if (listNode == NULL) return NULL;
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->listNode = listNode;
    node->next = NULL;
    return node;
}

struct Node* adjustNodeList(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* node = head;
    int headVal = head->listNode->val;
    while (node->next != NULL) {
        int nextVal = node->next->listNode->val;
        if (headVal > nextVal) {
            node = node->next;
        }
        else break;
    }
    if (head != node) {
        struct Node* temp = head->next;
        head->next = node->next;
        node->next = head;
        head = temp;
    }
    return head;
}

struct Node* insertNode(struct Node* head, struct Node* node) {
    if (node == NULL) return head;
    if (head == NULL) {
        head = node;
    } else {
        node->next = head;
        head = node;
        head = adjustNodeList(head);
    }
    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct Node* head = NULL;
    for (int i = 0; i < listsSize; i++) {
        struct Node* node = createNode(lists[i]);
        head = insertNode(head, node);
    }
    struct ListNode* resHead = NULL;
    struct ListNode* resTail = NULL;
    while (head != NULL) {
        if (resHead == NULL) {
            resHead = head->listNode;
        } else {
            resTail->next = head->listNode;
        }
        resTail = head->listNode;
        head->listNode = head->listNode->next;
        if (head->listNode == NULL) {
            struct Node* node = head;
            head = head->next;
            free(node);
        } else {
            head = adjustNodeList(head);
        }
    }
    return resHead;
}
