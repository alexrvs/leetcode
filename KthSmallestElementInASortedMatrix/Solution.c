struct Node {
    int row;
    int col;
    struct Node* next;
};

struct Node* createNode(int i, int j) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->row = i;
    node->col = j;
    node->next = NULL;
    return node;
}

int kthSmallest(int** matrix, int matrixRowSize, int matrixColSize, int k) {
    struct Node* head = createNode(0, 0);
    struct Node* tail = head;
    struct Node* node = NULL;
    struct Node* temp = NULL;
    for (int i = 1; i < matrixRowSize; i++) {
        tail->next = createNode(i, 0);
        tail = tail->next;
    }
    for (int i = 0; i < k - 1; i++) {
        head->col++;
        if (head->col >= matrixColSize) {
            node = head;
            head = head->next;
            free(node);
        } else {
            node = head;
            while (node->next != NULL ) {
                int cur = matrix[head->row][head->col];
                int val = matrix[node->next->row][node->next->col];
                if (cur > val) node = node->next;
                else break;
            }
            if (node != head) {
                temp = head;
                head = head->next;
                temp->next = node->next;
                node->next = temp;
            }
        }
    }
    int r = head->row;
    int c = head->col;
    while (head != NULL) {
        node = head->next;
        free(head);
        head = node;
    }
    return matrix[r][c];
}
