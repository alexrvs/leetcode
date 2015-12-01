public class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuffer sb = new StringBuffer();
        int l = strs.length;
        if (l == 0) return sb.toString();
        if (l == 1) return strs[0];
        int l0 = strs[0].length();
        for (int idx = 0; idx < l0; idx++) {
            char c = strs[0].charAt(idx);
            for (int i = 0; i < l; i++) {
                if (idx >= strs[i].length() || c != strs[i].charAt(idx)) {
                    return sb.toString();
                }
            }
            sb.append(c);
        }
        return sb.toString();
    }
}
