public class Solution {
    public boolean isAnagram(String s, String t) {
      int[] s_nums = new int[26];
      int[] t_nums = new int[26];
      for (int i = 0; i < 26; i++) {
        s_nums[i] = 0;
        t_nums[i] = 0;
      }
      for (int i = 0; i < s.length(); i++) {
        s_nums[s.charAt(i)-'a']++;
      }
      for (int i = 0; i < t.length(); i++) {
        t_nums[t.charAt(i)-'a']++;
      }
      for (int i = 0; i < 26; i++) {
        if (s_nums[i] != t_nums[i]) {
          return false;
        }
      }
      return true;
    }
}
