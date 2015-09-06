public class Solution {
    public int hIndex(int[] citations) {
        int size = citations.length;
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            cnt = size - i;
            if (citations[i] >= cnt) {
                return cnt;
            }
        }
        return 0;
    }
}
