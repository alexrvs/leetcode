class CacheNode{
public:
    int key, value;
    CacheNode(int key, int value):key(key), value(value) {}
};

class LRUCache {
public:
    int size;
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end())
            return -1;
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheList.begin()->value;
    }

    void set(int key, int value) {
        if (cacheMap.find(key) == cacheMap.end()) {
            cacheList.push_front(CacheNode(key,value));
            cacheMap.insert(make_pair(key, cacheList.begin()));
            if (cacheList.size() > size) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
        }
        else {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheList.begin()->value = value;
            cacheMap[key] = cacheList.begin();
        }
    }
};
