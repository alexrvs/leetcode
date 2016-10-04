public class Solution {
    public int longestPalindrome(String s) {
        int[] cnt = new int[52];
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                cnt[s.charAt(i) - 'a']++;
            } else if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
                cnt[s.charAt(i) - 'A' + 26]++;
            }
        }
        int max = 0;
        int hasEven = 0;
        for (int i = 0; i < 52; i++) {
            if (cnt[i] % 2 != 0) hasEven = 1;
            max += (cnt[i] / 2) * 2;
        }
        return max + hasEven;
    }
}