public class Solution {
    public int lastRemaining(int n) {
        int start = 1;
        int time = 1;
        int diff = 1;
        while (n > 1) {
            if (time % 2 == 1 || n % 2 == 1) {
                start += diff;
            }
            n -= (n + 1) >> 1;
            time++;
            diff <<= 1;
        }
        return start;
    }
}