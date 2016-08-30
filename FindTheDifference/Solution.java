public class Solution {
    public char findTheDifference(String s, String t) {
        int[] cnt = new int[26];
        for (int i = 0; i < t.length(); i++) {
            cnt[t.charAt(i) - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            cnt[s.charAt(i) - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 1) return Character.toChars('a' + i)[0];
        }
        return 'a';
    }
}
