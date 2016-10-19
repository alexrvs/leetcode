public class Solution {
    public int numDecodings(String s) {
        int len = s.length();
        if (len == 0) return 0;
        int[] cnt = new int[len];
        int prev = s.charAt(0) - '0';
        if (prev > 0 && prev <= 26) cnt[0] = 1;
        for (int i = 1; i < len; i++) {
            int cur = s.charAt(i) - '0';
            int sum = prev * 10 + cur;
            System.out.println(sum);
            prev = cur;
            
            /* when sum is 10-16, add cnt[i-2]
             * so that the string like "09" can be skipped
             */
            if (sum > 9 && sum <= 26) {
                if (i > 1) {
                    cnt[i] += cnt[i - 2];
                } else {
                    cnt[i] += 1;
                }
            }
            
            /* add cnt[i - 1] if current digit is valid (1 - 9)
             */
            if (cur > 0 && cur < 10){
                cnt[i] += cnt[i - 1];
            }
        }
        for (int i = 0; i < len; i++) {
            if (cnt[i] == 0) return 0;
        }
        return cnt[s.length() - 1];
    }
}