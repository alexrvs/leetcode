public class Solution {
    public int integerReplacement(int n) {
        int cnt = 0;
        long k = n;
        while (k > 3) {
            cnt++;
            if ((k & 1) != 0) {
                if ((k & 2) != 0) k++;
                else k--;
            }
            else k >>= 1;
        }
        return cnt + (int) k - 1;
    }
}
