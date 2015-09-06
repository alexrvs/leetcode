class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        vector<int> cnt(size+1, 0);
        for (int i = 0; i < size; i++) {
            if (citations[i] >= size) {
                cnt[size]++;
            } else {
                cnt[citations[i]]++;
            }
        }
        if (cnt[size] >= size) {
            return size;
        }
        for (int i = size - 1; i >= 0; i--) {
            cnt[i] += cnt[i+1];
            if (cnt[i] >= i) {
                return i;
            }
        }
        return 0;
    }
};
