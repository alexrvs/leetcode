struct Node {
    char ch;
    int idx;
    struct Node* next;
};

char* minWindow(char* s, char* t) {
    int lookup[255];
    int count[255];
    memset(lookup, 0, 255 * sizeof(int));
    memset(count, 0, 255 * sizeof(int));
    int sl = strlen(s);
    int tl = strlen(t);
    printf("%d\n", __LINE__);
    for (int i = 0; i < tl; i++) {
        lookup[t[i]]++;
    }
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int minL = -1;
    int start = -1;
    for (int i = 0; i < sl; i++) {
        char c = s[i];
        if (lookup[c] > 0) {
            count[c]++;
            struct Node* node = (struct Node*) malloc(sizeof(struct Node*));
            node->ch  = c;
            node->idx = i;
            node->next = NULL;
            if (head == NULL) {
                head = node;
            } else {
                tail->next = node;

            }
            tail = node;
            c = head->ch;
            while ( count[c] > lookup[c]) {
                count[c]--;
                struct Node* temp = head;
                head = head->next;
                free(temp);
                c = head->ch;
            }
            int match = 1;
            for (int i = 0; i < 255; i++) {
                if (count[i] < lookup[i]) {
                    match = 0;
                }
            }
            if (match == 1) {
                int len = tail->idx - head->idx + 1;
                if (len < minL || minL == -1) {
                    minL = len;
                    start = head->idx;
                }
            }
        }
    }
    tail = NULL;
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    char* res = NULL;
    if (minL == -1) {
        res = (char*) malloc(sizeof(char));
        res[0] = 0;
        return res;
    }
    res = (char*) malloc((minL + 1) * sizeof(char));
    memset(res, 0, (minL + 1) * sizeof(char));
    int idx = 0;
    for (int i = start; i < start + minL; i++) {
        res[idx++] = s[i];
    }
    return res;
}
