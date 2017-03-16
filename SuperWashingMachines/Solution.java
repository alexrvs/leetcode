public class Solution {
    public int findMinMoves(int[] machines) {
        int size = machines.length;
        int[] sums = new int[size + 1];
        for (int i = 0; i < size; i++) {
             sums[i + 1] += sums[i] + machines[i];
        }
        if (sums[size] % size != 0) return -1;
        int avg = sums[size] / size;
        int res = 0;
        for (int i = 0; i < size; i++) {
            int l = avg * i - sums[i];
            int r = avg * (size - 1 - i) - (sums[size] - sums[i + 1]);
            if (l > 0 && r > 0) {
                res = Math.max(res, l + r);
            } else {
                res = Math.max(res, Math.max(Math.abs(l), Math.abs(r)));
            }
        }
        return res;
    }
}