public class AllOne {
    
    private class KeyNode {
        
        public String key;
        public int cnt;
        public KeyNode prev;
        public KeyNode next;
        
        public KeyNode(String key, int cnt) {
            this.key = key;
            this.cnt = cnt;
            this.prev = null;
            this.next = null;
        }
        
    }
    
    private Map<String, KeyNode> keyMap;
    private KeyNode head;
    private KeyNode tail;

    /** Initialize your data structure here. */
    public AllOne() {
        this.keyMap = new HashMap<String, KeyNode>();
        this.head = null;
        this.tail = null;
    }
    
    private void adjustNodeList(KeyNode node) {
        KeyNode prevNode = node.prev;
        KeyNode nextNode = node.next;
        
        while (prevNode != null && prevNode.cnt < node.cnt) {

            if (prevNode.prev != null) prevNode.prev.next = node;
            node.prev = prevNode.prev;
            prevNode.prev = node;

            if (node.next != null) node.next.prev = prevNode;
            prevNode.next = node.next;
            node.next = prevNode;

            if (prevNode == this.head) {
                this.head = node;
            }
            if (node == this.tail) this.tail = prevNode;
            prevNode = node.prev;
        }
        
        while (nextNode != null && node.cnt < nextNode.cnt) {

            if (nextNode.next != null) nextNode.next.prev = node;
            node.next = nextNode.next;
            nextNode.next = node;

            if (node.prev != null) node.prev.next = nextNode;
            nextNode.prev = node.prev;
            node.prev = nextNode;

            if (nextNode == this.tail) {
                this.tail = node;
            }
            if (node == this.head) this.head = nextNode;
            nextNode = node.next;
        }
    }
    
    private void removeNode(KeyNode node) {
        KeyNode prevNode = node.prev;
        KeyNode nextNode = node.next;
        
        if (prevNode == null && nextNode == null) {
            this.head = null;
            this.tail = null;
        } else if (prevNode == null && nextNode != null) {
            this.head = nextNode;
            nextNode.prev = null;
        } else if (prevNode != null && nextNode == null) {
            this.tail = prevNode;
            prevNode.next = null;
        } else {
            prevNode.next = nextNode;
            nextNode.prev = prevNode;
        }
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    public void inc(String key) {
        if (keyMap.containsKey(key)) {
            KeyNode node = keyMap.get(key);
            node.cnt++;
            adjustNodeList(node);
        } else {
            KeyNode node = new KeyNode(key, 1);
            keyMap.put(key, node);
            if (head == null) head = node;
            if (tail != null) tail.next = node;
            node.prev = tail;
            tail = node;
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    public void dec(String key) {
        if (keyMap.containsKey(key)) {
            KeyNode node = keyMap.get(key);
            node.cnt--;
            if (node.cnt == 0) {
                keyMap.remove(key);
                removeNode(node);
            } else {
                adjustNodeList(node);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    public String getMaxKey() {
        if (this.head == null) return "";
        return this.head.key;
    }
    
    /** Returns one of the keys with Minimal value. */
    public String getMinKey() {
        if (this.tail == null) return "";
        return this.tail.key;
    }
    
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */