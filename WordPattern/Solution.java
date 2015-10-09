public class Solution {
    public boolean wordPattern(String pattern, String str) {
        Map<Character, String> m = new HashMap<Character, String>();
        int psize = pattern.length();
        String[] words = str.split(" ");
        int wsize = words.length;
        if (psize != wsize) return false;
        for (int i = 0; i < psize; i++) {
            char c = pattern.charAt(i);
            if (m.containsKey(c)) {
                if(!m.get(c).equals(words[i])) return false;
            } else {
                if(m.containsValue(words[i])) return false;
                m.put(c, words[i]);
            }
        }
        return true;
    }
}
