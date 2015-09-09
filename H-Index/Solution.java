public class Solution {
    public int hIndex(int[] citations) {
        int size = citations.length;
        int[] cnt = new int[size + 1];
        for (int i = 0; i < size; i++) {
            if (citations[i] > size - 1) {
                cnt[size]++;
            } else {
                cnt[citations[i]]++;
            }
        }
        if (cnt[size] >= size) return size;
        for (int i = size - 1; i >= 0; i--) {
            cnt[i] += cnt[i+1];
            if (cnt[i] >= i) {
                return i;
            }
        }
        return 0;
    }
}
