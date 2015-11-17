public class Solution {
    public boolean isIsomorphic(String s, String t) {
        int l = s.length();
        Map<Character, Character> m1 = new HashMap<Character, Character>();
        Map<Character, Character> m2 = new HashMap<Character, Character>();
        for (int i = 0; i < l; i++) {
            char cs = s.charAt(i);
            char ct = t.charAt(i);
            if (m1.containsKey(cs)) {
                if (ct != m1.get(cs)) return false;
            } else {
                m1.put(cs, ct);
            }
            if (m2.containsKey(ct)) {
                if (cs != m2.get(ct)) return false;
            } else {
                m2.put(ct, cs);
            }
        }
        return true;
    }
}
