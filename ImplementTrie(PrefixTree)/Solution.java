class TrieNode {
    private List<TrieNode> children;
    private boolean isEnded;
    // Initialize your data structure here.
    public TrieNode() {
       this.children = new ArrayList<TrieNode>();
       for (int i = 0; i < 26; i++) {
           this.children.add(null);
       }
       this.isEnded = false;
    }

    public List<TrieNode> getChildren() {
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
        TrieNode child = node.getChildren().get(c - 'a');
        if (null == child) {
            child = new TrieNode();
            node.getChildren().set(c - 'a', child);
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

    private boolean searchHelper(TrieNode node, String word, int index, boolean needEnded) {
        if (index >= word.length()) return true;
        char c = word.charAt(index);
        TrieNode child = node.getChildren().get(c - 'a');
        if (null == child) return false;
        if (true == needEnded && index + 1 == word.length()) {
            if (true == child.isEnded()) return true;
            return false;
        }
        return searchHelper(child, word, index + 1, needEnded);
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
        return searchHelper(this.root, word, 0, true);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        return searchHelper(this.root, prefix, 0, false);
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");
