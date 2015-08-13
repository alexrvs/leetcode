public class Solution {
  public int lengthOfLongestSubstring(String s) {
    int start = 0;
    int len = 0;
    int max = 0;
    int i = 0;
    if (s.length() == 0)
      return 0;
    for (i = 1; i < s.length(); i++) {
      for (int j = start; j < i; j++) {
        if ( s.charAt(j) == s.charAt(i) ) {
          len = i - start;
          for (int k = start; k < i; k++)
          if (max < len)
          max = len;
          start = j+1;
          break;
        }
      }
    }
    len = i - start;
    if (max < len)
      max = len;
    return max;
  }
}
