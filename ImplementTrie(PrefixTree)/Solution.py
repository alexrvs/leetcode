class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.children = {}
        self.isEnded = False

    def getChild(self, c):
        if (c in self.children):
            return self.children[c]
        return None

    def setChild(self, c, node):
        self.children[c] = node

class Trie(object):

    def __init__(self):
        self.root = TrieNode()

    def insertHelper(self, node, word, index):
        l = len(word)
        if index >= l:
            return
        c = word[index]
        child = node.getChild(c)
        if None == child:
            child = TrieNode()
            node.setChild(c, child)
        if index + 1 == l:
            child.isEnded = True
        self.insertHelper(child, word, index + 1)

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        if True == self.search(word):
            return
        self.insertHelper(self.root, word, 0)
        return

    def searchHelper(self, node, word, index, needEnded):
        l = len(word)
        if (index >= l):
            return True
        c = word[index]
        child = node.getChild(c)
        if (None == child):
            return False
        if True == needEnded and index + 1 == l:
            return child.isEnded
        return self.searchHelper(child, word, index + 1, needEnded)

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        return self.searchHelper(self.root, word, 0, True)

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie
        that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        return self.searchHelper(self.root, prefix, 0, False)

# Your Trie object will be instantiated and called as such:
# trie = Trie()
# trie.insert("somestring")
# trie.search("key")
