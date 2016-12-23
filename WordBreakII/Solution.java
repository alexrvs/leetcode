public class Solution {
    private Map<String, List<String>> dp = null;
    private Set<String> words = null;
    
    private List<String> helper(String s) {
        if (dp.containsKey(s)) {
            return dp.get(s);
        }
        
        List<String> res = new ArrayList<String>();
        if (s.length() == 0) {
            res.add("");
            return res;
        }
        
        for (String word : words) {
            if (s.startsWith(word)) {
                List<String> suffixes = helper(s.substring(word.length()));
                for (String suffix : suffixes) {
                    if (suffix.length() == 0) {
                        res.add(word);
                    } else {
                        res.add(word + " " + suffix);
                    }
                }
            }
        }
        dp.put(s, res);
        return res;
    }
    
    public List<String> wordBreak(String s, Set<String> wordDict) {
        dp = new HashMap<String, List<String>>();
        words = wordDict;
        return helper(s);
    }
}