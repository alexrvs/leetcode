public class Solution {
    private Map<String, Boolean> pair = new HashMap<String, Boolean>();

    public boolean isScramble(String s1, String s2) {
        String comb = s1 + "|" + s2;
        if (s1.equals(s2)) {
            this.pair.put(comb, true);
            return true;
        }
        int l = s1.length();
        if (this.pair.containsKey(comb)) return this.pair.get(comb);
        for (int i = 1; i < l; i++) {
            if (isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i, l), s2.substring(i, l))) {
                this.pair.put(comb, true);
                return true;
            }
            if (isScramble(s1.substring(0, i), s2.substring(l - i, l)) && isScramble(s1.substring(i, l), s2.substring(0, l - i))) {
                this.pair.put(comb, true);
                return true;
            }
        }
        this.pair.put(comb, false);
        return false;
    }
}
