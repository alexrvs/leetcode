class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int> > pos;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        pos[val].insert(nums.size() - 1);
        return pos[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (pos.find(val) == pos.end()) return false;
        int lastVal = nums.back();
        if (lastVal != val) {
            int idx = *pos[val].begin();
            nums[idx] = lastVal;
            pos[val].erase(idx);
            pos[lastVal].insert(idx);
        }
        pos[lastVal].erase(nums.size() - 1);
        nums.pop_back();
        if (pos[val].empty()) pos.erase(val);
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
