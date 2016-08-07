/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct Node {
    int i;
    int j;
    struct Node* next;
};

struct Node* createNode(int i, int j) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->i = i;
    node->j = j;
    node->next = NULL;
    return node;
}

struct Node* adjustNodeList(int* nums1, int* nums2, struct Node* head) {
    struct Node* node = head;
    int headVal = nums1[head->i] + nums2[head->j];
    while (node->next != NULL) {
        int nextVal = nums1[node->next->i] + nums2[node->next->j];
        if (headVal > nextVal) node = node->next;
        else break;
    }
    struct Node* temp = head;
    if (head != node) {
        head = head->next;
        temp->next = node->next;
        node->next = temp;
    }
    return head;
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int** columnSizes, int* returnSize) {
    struct Node* head = NULL;
    struct Node* node = NULL;
    struct Node* tail = NULL;
    int** res = (int**) malloc(k * sizeof(int*));
    *columnSizes = (int*) malloc(k * sizeof(int));
    *returnSize = 0;
    if (nums1Size == 0 || nums2Size == 0) return res;
    for (int i = 0; i < nums1Size; i++) {
        node = createNode(i, 0);
        if (head == NULL) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }
    for (int i = 0; i < k && head != NULL; i++) {
        int* pair = (int*) malloc(2 * sizeof(int));
        pair[0] = nums1[head->i];
        pair[1] = nums2[head->j];
        res[i] = pair;
        head->j += 1;
        if (head->j >= nums2Size) {
            node = head;
            head = head->next;
            free(node);
        } else {
            head = adjustNodeList(nums1, nums2, head);
        }
        (*columnSizes)[i] = 2;
        *returnSize += 1;
    }
    return res;
}
