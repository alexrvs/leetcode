public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int size1 = s1.length();
        int size2 = s2.length();
        int size3 = s3.length();
        if (size1 + size2 != size3) return false;
        boolean[][] dp = new boolean[size1 + 1][size2 + 1];
        for (int i = 0; i <= size1; i++) {
            for (int j = 0; j <= size2; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = (dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
                } else if (j == 0) {
                    dp[i][j] = (dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1));
                } else {
                    dp[i][j] = ((dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1)) || (dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)));
                }
            }
        }
        return dp[size1][size2];
    }
}