public class Solution {
    private class Pattern {
        int[] cnt;
        Pattern(String str) {
            cnt = new int[26];
            for (int i = 0; i < str.length(); i++) {
                cnt[str.charAt(i) - 'a']++;
            }
        }
        
        public int[] getCounts() {
            return this.cnt;
        }
        
        public boolean equals(Object obj) {
            Pattern pattern = (Pattern) obj;
            int[] p_cnt = pattern.getCounts();
            for (int i = 0; i < 26; i++) {
                if (this.cnt[i] != p_cnt[i]) return false;
            }
            return true;
        }
        
        public int hashCode() {
            int hash = 0;
            for (int i = 0; i < 26; i++) {
                hash += (i + 1) * cnt[i];
            }
            return hash;
        }
    }
    
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<Pattern, List<String>> map = new HashMap<Pattern, List<String>>();
        for (int i = 0; i < strs.length; i++) {
            Pattern pattern = new Pattern(strs[i]);
            if (!map.containsKey(pattern)) {
                map.put(pattern, new ArrayList<String>());
            }
            map.get(pattern).add(strs[i]);
        }
        List<List<String>> res = new ArrayList<List<String>>();
        for (Map.Entry<Pattern, List<String>> entry : map.entrySet()) {
            res.add(entry.getValue());
        }
        return res;
    }
}