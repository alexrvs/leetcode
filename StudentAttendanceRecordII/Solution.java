public class Solution {
    public int checkRecord(int n) {
        int mod = 1000000007;
        long[][] al = new long[2][3];
        al[0][0] = 1;
        for (int i = 0; i <= n; i++) {
            long a = (al[0][0] + al[0][1] + al[0][2]) % mod;
            al[0][2] = al[0][1];
            al[0][1] = al[0][0];
            al[0][0] = a;
            a += al[1][0] + al[1][1] + al[1][2];
            a %= mod;
            al[1][2] = al[1][1];
            al[1][1] = al[1][0];
            al[1][0] = a;
        }
        return (int) al[1][0];
    }
}