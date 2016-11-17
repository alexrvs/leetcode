public class Solution {
    private boolean isSame(String str, int pl, int s) {
        for (int i = 0; i < pl; i++) {
            if (str.charAt(i) != str.charAt(s + i)) return false;
        }
        return true;
    }
    
    public boolean repeatedSubstringPattern(String str) {
        int size = str.length();
        for (int l = 1; l <= size / 2; l++) {
            if (size % l == 0) {
                boolean isRepeated = true;
                for (int s = l; s < size; s += l) {
                    if (false == isSame(str, l, s)) {
                        isRepeated = false;
                        break;
                    }
                }
                if (isRepeated == true) return true;
            }
        }
        return false;
    }
}