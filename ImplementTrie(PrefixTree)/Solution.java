class TrieNode {
    private Map<Character, TrieNode> children;
    private boolean isEnded;
    // Initialize your data structure here.
    public TrieNode() {
       this.children = new HashMap<Character, TrieNode>();
       this.isEnded = false;
    }

    public Map<Character, TrieNode> getChildren() {
        return this.children;
    }

    public void setEnded() {
        this.isEnded = true;
    }

    public boolean isEnded() {
        return this.isEnded;
    }
}

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    private void insertHelper(TrieNode node, String word, int index) {
        if (index == word.length()) return;
        char c = word.charAt(index);
        TrieNode child = node.getChildren().get(c);
        if (null == child) {
            child = new TrieNode();
            node.getChildren().put(c, child);
        }
        if (index + 1 == word.length()) {
            child.setEnded();
            return;
        }
        insertHelper(child, word, index + 1);
    }

    // Inserts a word into the trie.
    public void insert(String word) {
        if (true == search(word)) return;
        insertHelper(this.root, word, 0);
    }

    private boolean searchHelper(TrieNode node, String word, int index) {
        if (index > word.length()) return false;
        char c = word.charAt(index);
        TrieNode child = node.getChildren().get(c);
        if (null == child) return false;
        if (index + 1 == word.length()) {
            if (true == child.isEnded()) return true;
            return false;
        }
        return searchHelper(child, word, index + 1);
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
        return searchHelper(this.root, word, 0);
    }

    private boolean startsWithHelper(TrieNode node, String prefix, int index) {
        if (index == prefix.length()) return true;
        char c = prefix.charAt(index);
        TrieNode child = node.getChildren().get(c);
        if (null == child) return false;
        return startsWithHelper(child, prefix, index + 1);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        return startsWithHelper(this.root, prefix, 0);
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");
