/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addNode(struct ListNode * list, int i) {
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->val = i;
    newNode->next = NULL;
    if (list == NULL)
        list = newNode;
    else {
        struct ListNode * tmp = list;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    return list;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum,num1,num2,in,digit;
    sum = num1 = num2 = in = digit = 0;
    struct ListNode* n1 = l1;
    struct ListNode* n2 = l2;
    struct ListNode* result = NULL;
    while (n1 != NULL || n2 != NULL) {
        num1 = 0;
        num2 = 0;
        if (n1 != NULL) {
            num1 = n1->val;
            n1 = n1->next;
        }
        if (n2 != NULL) {
            num2 = n2->val;
            n2 = n2->next;
        }
        sum = num1 + num2 + in;
        digit = sum%10;
        in = sum/10;
        result = addNode(result, digit);
    }
    if (in != 0)
        result = addNode(result, in);
    return result;
}
