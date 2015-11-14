class TrieNode
    # Initialize your data structure here.
    def initialize
        @children = {}
        @isEnded = false
    end

    def getChild(c)
        return @children[c]
    end

    def setChild(c, node)
        @children[c] = node
    end

    def isEnded
        return @isEnded
    end

    def setEnded
        @isEnded = true
    end

end

class Trie
    def initialize
        @root = TrieNode.new
    end

    def insertHelper(node, word, index)
        return if index >= word.length
        c = word[index]
        child = node.getChild(c)
        if nil == child
            child = TrieNode.new
            node.setChild(c, child)
        end
        if index + 1 == word.length
            child.setEnded()
        end
        insertHelper(child, word, index + 1)
    end

    # @param {string} word
    # @return {void}
    # Inserts a word into the trie.
    def insert(word)
        return if true == search(word)
        insertHelper(@root, word, 0)
    end

    def searchHelper(node, word, index, needEnded)
        return true if index >= word.length
        c = word[index]
        child = node.getChild(c)
        return false if nil == child
        return child.isEnded() if true == needEnded && index + 1 == word.length
        return searchHelper(child, word, index + 1, needEnded)
    end

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the trie.
    def search(word)
        return searchHelper(@root, word, 0, true)
    end

    # @param {string} prefix
    # @return {boolean}
    # Returns if there is any word in the trie
    # that starts with the given prefix.
    def starts_with(prefix)
        return searchHelper(@root, prefix, 0, false)
    end
end

# Your Trie object will be instantiated and called as such:
# trie = Trie.new
# trie.insert("somestring")
# trie.search("key")
