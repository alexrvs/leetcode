public class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<String, Integer> cnt = new HashMap<String, Integer>();
        List<String> res = new ArrayList<String>();
        for (int i = 0; i < 10; i++) {
            for (int j = i; j + 10 <= s.length(); j += 10) {
                String sub = s.substring(j, j + 10);
                int c = 0;
                if (cnt.containsKey(sub)) {
                    c = cnt.get(sub);
                }
                cnt.put(sub, c + 1);
            }
        }
        for (String key : cnt.keySet()) {
            if (cnt.get(key) > 1) res.add(key);
        }
        return res;
    }
}
