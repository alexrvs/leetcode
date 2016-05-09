struct TrieNode {
    struct TrieNode* children[26];
    bool isEnded;
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    struct TrieNode* node = (struct TrieNode*) malloc(sizeof(struct TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->isEnded = true;
    return node;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
    int i = 0;
    struct TrieNode* node = NULL;
    if (*word == 0) return;
    i = *word - 'a';
    if (root->children[i] == NULL) {
        node = (struct TrieNode*) malloc(sizeof(struct TrieNode));
        node->isEnded = true;
        root->children[i] = node;
    }
    root->isEnded = false;
    insert(root->children[i], word + 1);
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
    int i = 0;
    if (*word == 0) return true;
    i = *word - 'a';
    if (root->children[i] == NULL) return false;
    if (*(word + 1) == 0 && root->isEnded == true) return true;
    return search(root->children[i], word + 1);
}

/** Returns if there is any word in the trie
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    int i = 0;
    if (*prefix == 0) return true;
    i = *prefix - 'a';
    if (root->children[i] == NULL) return false;
    return startsWith(root->children[i], prefix + 1);
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    if (root == NULL) return;
    for (int i = 0; i < 26; i++) {
        trieFree(root->children[i]);
    }
    free(root);
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);
