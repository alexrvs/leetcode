/**
 * @constructor
 * Initialize your data structure here.
 */
var TrieNode = function() {
    this.children = {};
    this.isEnded = false;
};

TrieNode.prototype.getChild = function(c) {
    return this.children[c];
};

TrieNode.prototype.setChild = function(c, node) {
    this.children[c] = node;
};

var Trie = function() {
    this.root = new TrieNode();
};

Trie.prototype.insertHelper = function(node, word, index) {
    if (index >= word.length) return;
    var c = word[index];
    var child = node.getChild(c);
    if (undefined === child) {
        child = new TrieNode();
        node.setChild(c, child);
    }
    if (index + 1 == word.length) {
        child.isEnded = true;
    }
    this.insertHelper(child, word, index + 1);
};

/**
 * @param {string} word
 * @return {void}
 * Inserts a word into the trie.
 */
Trie.prototype.insert = function(word) {
    if (true === this.search(word)) return;
    this.insertHelper(this.root, word, 0);
};

Trie.prototype.searchHelper = function(node, word, index, needEnded) {
    if (index >= word.length) return true;
    var child = node.getChild(word[index]);
    if (undefined === child) return false;
    if (true === needEnded && index + 1 == word.length) return child.isEnded;
    return this.searchHelper(child, word, index + 1, needEnded);
};

/**
 * @param {string} word
 * @return {boolean}
 * Returns if the word is in the trie.
 */
Trie.prototype.search = function(word) {
    return this.searchHelper(this.root, word, 0, true);
};

/**
 * @param {string} prefix
 * @return {boolean}
 * Returns if there is any word in the trie
 * that starts with the given prefix.
 */
Trie.prototype.startsWith = function(prefix) {
    return this.searchHelper(this.root, prefix, 0, false);
};

/**
 * Your Trie object will be instantiated and called as such:
 * var trie = new Trie();
 * trie.insert("somestring");
 * trie.search("key");
 */
