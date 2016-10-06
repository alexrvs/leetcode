typedef struct {
    struct ListNode* head;
    int len;
} Solution;

/** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
Solution* solutionCreate(struct ListNode* head) {
    Solution* s = (Solution*) malloc(sizeof(Solution));
    s->head = head;
    s->len = 0;
    while (head != NULL) {
        s->len++;
        head = head->next;
    }
    return s;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
    int step = rand() % obj->len;
    struct ListNode* cur = obj->head;
    while (step-- != 0) {
        cur = cur->next;
    }
    return cur->val;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 * solutionFree(obj);
 */
