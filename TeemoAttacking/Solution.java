public class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int size = timeSeries.length;
        if (size == 0) return 0;
        int res = duration;
        for (int i = 1; i < size; i++) {
            int diff = timeSeries[i] - timeSeries[i - 1];
            if (diff < duration) {
                res += diff;
            } else {
                res += duration;
            }
        }
        return res;
    }
}