public class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int k = primes.length;
        int[] idx = new int[k];
        int[] un = new int[n + 1];
        un[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int num = primes[j] * un[idx[j]];
                if (un[i] == 0 || num < un[i]) {
                    un[i] = num;
                }
            }
            for (int j = 0; j < k; j++) {
                int num = primes[j] * un[idx[j]];
                if (un[i] == num) {
                    idx[j]++;
                }
            }
        }
        return un[n - 1];
    }
}
