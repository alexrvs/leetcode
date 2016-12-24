public class LFUCache {
    
    protected static class CacheNode {
        
        protected int key;
        protected int val;
        protected CacheNode prev;
        protected CacheNode next;
        protected int cnt;
        
        protected CacheNode(int key, int val) {
            this.key = key;
            this.val = val;
            this.cnt = 0;
            this.prev = null;
            this.next = null;
        }
    }
    
    private CacheNode head = null;
    private CacheNode tail = null;
    Map<Integer, CacheNode> cacheMap = null;
    int capa;
    int size;

    public LFUCache(int capacity) {
        this.capa = capacity;
        this.size = 0;
        this.cacheMap = new HashMap<Integer, CacheNode>();
    }
    
    public int get(int key) {
        if (capa == 0) return -1;
        if (cacheMap.containsKey(key)) {
            CacheNode node = cacheMap.get(key);
            node.cnt++;
            adjustNode(node);
            return node.val;
        }
        return -1;
    }
    
    public void set(int key, int value) {
        if (capa == 0) return;
        if (cacheMap.containsKey(key)) {
            CacheNode node = cacheMap.get(key);
            node.val = value;
            node.cnt++;
            adjustNode(node);
        } else {
            CacheNode node = new CacheNode(key, value);
            node.cnt++;
            cacheMap.put(key, node);
            addNode(node);
        }
    }
    
    private void adjustNode(CacheNode node) {
        CacheNode prevNode = node.prev;
        CacheNode nextNode = node.next;
        CacheNode newPrev = node.prev;
        
        if (prevNode == null || prevNode.cnt > node.cnt) {
            return;
        }
        
        while (newPrev != null && newPrev.cnt <= node.cnt) {
            newPrev = newPrev.prev;
        }
        
        prevNode.next = nextNode;
        if (nextNode != null) {
            nextNode.prev = prevNode;
        } else {
            tail = prevNode;
        }
        
        if (newPrev != null) {
            CacheNode tmp = newPrev.next;
            node.next = tmp;
            tmp.prev = node;
            newPrev.next = node;
            node.prev = newPrev;
        } else {
            node.next = head;
            node.prev = null;
            head.prev = node;
            head = node;
        }
        
        return;
    }
    
    private void checkAndRemoveTail() {
        if (size == capa) {
            CacheNode tmp = tail;
            int key = tail.key;
            tail = tail.prev;
            if (tail != null) {
                tail.next = null;
            } else {
                head = null;
            }
            tmp.prev = null;
            cacheMap.remove(key);
            size--;
        }
        return;
    }
    
    private void addNode(CacheNode node) {
        checkAndRemoveTail();
        if (head == null) {
            head = node;
            tail = node;
            size++;
        } else {
            tail.next = node;
            node.prev = tail;
            tail = node;
            size++;
            adjustNode(node);
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */