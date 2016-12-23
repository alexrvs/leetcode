public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {
        int len = s.length();
        boolean[] dp = new boolean[len + 1];
        dp[0] = true;
        for (int end = 1; end <= len; end++) {
            for (int start = 0; start < end; start++) {
                if (true == dp[start]) {
                    String substr = s.substring(start, end);
                    if (wordDict.contains(substr)) {
                        dp[end] = true;
                        break;
                    }
                }
            }
        }
        return dp[len];
    }
}