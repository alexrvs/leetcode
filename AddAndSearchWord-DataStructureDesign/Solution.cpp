class DictNode {
public:
    DictNode* nodes[26];
    bool isEnded;
    
    DictNode() {
        for (int i = 0; i < 26; i++) {
            nodes[i] = NULL;
        }
        isEnded = false;
    }
    
    ~DictNode() {
        for (int i = 0; i < 26; i++) {
            if (nodes[i] != NULL) {
                delete nodes[i];
            }
        }
    }
};

class WordDictionary {
private:
    DictNode* root;

    void addHelper(DictNode* node, int idx, string& word) {
        char c = word[idx];
        DictNode** nextNode = &node->nodes[c - 'a'];
        if (*nextNode == NULL) {
            *nextNode = new DictNode();
        }
        if (idx == word.size() - 1) {
            (*nextNode)->isEnded = true;
            return;
        }
        addHelper(*nextNode, idx + 1, word);
    }
    
    bool searchHelper(DictNode* node, int idx, string& word) {
        char c = word[idx];
        DictNode *nextNode = NULL;
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                nextNode = node->nodes[i];
                if (nextNode != NULL) {
                    if (true == nextNode->isEnded && idx == word.size() - 1) {
                        return true;
                    } else if (true == searchHelper(nextNode, idx + 1, word)) {
                        return true;
                    }
                }
            }
            return false;
        }
        nextNode = node->nodes[c - 'a'];
        if (nextNode != NULL) {
            if (idx == word.size() - 1 && nextNode->isEnded == true) {
                return true;
            }
            return idx + 1 < word.size() && searchHelper(nextNode, idx + 1, word);
        }
        return false;
    }
    
public:
    WordDictionary() {
        root = new DictNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        addHelper(root, 0, word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper(root, 0, word);
    }
    
    ~WordDictionary() {
        delete root;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");