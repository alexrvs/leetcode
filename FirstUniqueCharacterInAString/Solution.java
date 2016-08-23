public class Solution {
    public int firstUniqChar(String s) {
        int[] cnt = new int[26];
        int size = s.length();
        for (int i = 0; i < size; i++) {
            cnt[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < size; i++) {
            if (cnt[s.charAt(i) - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
}
