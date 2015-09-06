public class Solution {
    public int hIndex(int[] citations) {
        int size = citations.length;
        int hIndex = 0;
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            cnt = size - i;
            if (citations[i] >= cnt) {
                if (hIndex < cnt) {
                    hIndex = cnt;
                }
            }
        }
        return hIndex;
    }
}
