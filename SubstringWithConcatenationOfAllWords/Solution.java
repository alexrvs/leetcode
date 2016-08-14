public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        Map<String, Integer> cnt = new HashMap<String, Integer>();
        int size = words.length;
        int wlen = words[0].length();
        int slen = s.length();
        for (String word : words) {
            int c = 1;
            if (cnt.containsKey(word)) {
                c += cnt.get(word);
            }
            cnt.put(word, c);
        }
        Map<String, Integer> seen = new HashMap<String, Integer>();
        List<Integer> res = new ArrayList<Integer>();
        for (int i = 0; i < slen - size * wlen + 1; i++) {
            seen.clear();
            int j = 0;
            for (; j < size; j++) {
                int idx = i + j * wlen;
                String w = s.substring(idx, idx + wlen);
                if (cnt.containsKey(w)) {
                    int c = 1;
                    if (seen.containsKey(w)) {
                        c += seen.get(w);
                    }
                    seen.put(w, c);
                } else break;
                if (seen.get(w) > cnt.get(w)) break;
            }
            if (j == size) res.add(i);
        }
        return res;
    }
}
