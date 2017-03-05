public class Solution {
    public String findLongestWord(String s, List<String> d) {
        Map<String, Integer> idxMap = new HashMap<String, Integer>();
        for (String word : d) {
            idxMap.put(word, 0);
        }
        String res = "";
        for (char c : s.toCharArray()) {
            for (String word : d) {
                int idx = idxMap.get(word);
                if (idx < word.length() && word.charAt(idx) == c) {
                    idx += 1;
                    idxMap.put(word, idx);
                    if (idx == word.length()) {
                        if (idx > res.length() || (idx == res.length() && word.compareTo(res) < 0)) {
                            res = word;
                        }
                    }
                }
            }
        }
        return res;
    }
}