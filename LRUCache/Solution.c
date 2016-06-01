#include <stdlib.h>
#include <stdio.h>

struct DequeNode {
    int key;
    int val;
    struct DequeNode* next;
    struct DequeNode* prev;
};

static struct {
    struct DequeNode* head;
    struct DequeNode* tail;
    int size;
    int capa;
} LRUCache;

void dumpNode(struct DequeNode* node) {
    printf("%d->%d, ", node->key, node->val);
    return;
}

void dumpCache() {
    printf("size %d capa %d cache: ", LRUCache.size, LRUCache.capa);
    struct DequeNode* node = LRUCache.head;
    while (node != NULL) {
        dumpNode(node);
        node = node->next;
    }
    printf("\n");
    return;
}

void lruCacheInit(int capacity) {
    LRUCache.head = NULL;
    LRUCache.tail = NULL;
    LRUCache.size = 0;
    LRUCache.capa = capacity;
}

void lruCacheFree() {
    struct DequeNode* node = NULL;
    while (LRUCache.head != NULL) {
        node = LRUCache.head->next;
        free(LRUCache.head);
        LRUCache.head = node;
    }
    LRUCache.tail = NULL;
    LRUCache.size = 0;
    LRUCache.capa = 0;
}

struct DequeNode* lruCacheGetNode(int key) {
    struct DequeNode* node = LRUCache.head;
    while (node != NULL) {
        if (node->key == key) {
            if (node->next != NULL) {
                node->next->prev = node->prev;
            } else {
                LRUCache.tail = node->prev;
            }
            if (node->prev != NULL) {
                node->prev->next = node->next;
            } else {
                LRUCache.head = node->next;
            }
            node->prev = NULL;
            node->next = NULL;
            LRUCache.size--;
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void lruCachePopTail() {
    struct DequeNode* node = LRUCache.tail->prev;
    free(LRUCache.tail);
    if (node != NULL) node->next = NULL;
    LRUCache.tail = node;
    if (LRUCache.size == 1) {
        LRUCache.head = NULL;
    }
    LRUCache.size--;
}

void lruCachePushHead(struct DequeNode* node) {
    if (LRUCache.size == LRUCache.capa) {
        lruCachePopTail();
    }
    node->next = LRUCache.head;
    if (LRUCache.head != NULL) LRUCache.head->prev = node;
    LRUCache.head = node;
    if (LRUCache.size == 0) {
        LRUCache.tail = node;
    }
    LRUCache.size++;
}

int lruCacheGet(int key) {
    struct DequeNode* node = lruCacheGetNode(key);
    if (NULL != node) {
        lruCachePushHead(node);
        return node->val;
    }
    return -1;
}

void lruCacheSet(int key, int value) {
    struct DequeNode* node = lruCacheGetNode(key);
    if (NULL == node) {
        node = (struct DequeNode*) malloc(sizeof(struct DequeNode));
        node->key = key;
        node->val = value;
        node->prev = NULL;
        node->next = NULL;
    }
    node->val = value;
    lruCachePushHead(node);
}

int main(int argc, char ** argv) {
    lruCacheInit(3);
    dumpCache();
    lruCacheSet(1,1);
    dumpCache();
    lruCacheSet(2,2);
    dumpCache();
    lruCacheSet(3,3);
    dumpCache();
    lruCacheSet(4,4);
    dumpCache();
    lruCacheSet(5,5);
    dumpCache();
    printf("%d\n", lruCacheGet(4));
    dumpCache();
    printf("%d\n", lruCacheGet(0));
    dumpCache();
    lruCacheFree();
    return 0;
}
