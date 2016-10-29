public class Solution {
    private boolean compare(int[] sCnt, int[] pCnt) {
        for (int i = 0; i < pCnt.length; i++) {
            if (sCnt[i] != pCnt[i]) return false;
        }
        return true;
    }
    
    public List<Integer> findAnagrams(String s, String p) {
        int sLen = s.length();
        int pLen = p.length();
        List<Integer> res = new ArrayList<Integer>();
        if (sLen < pLen) return res;
        int[] pCnt = new int[26];
        int[] sCnt = new int[26];
        for (int i = 0; i < pLen; i++) {
            pCnt[p.charAt(i) - 'a']++;
        }
        for (int i = 0; i < pLen; i++) {
            sCnt[s.charAt(i) - 'a']++;
        }
        if (true == compare(sCnt, pCnt)) {
            res.add(0);
        }
        for (int i = pLen; i < sLen; i++) {
            sCnt[s.charAt(i - pLen) - 'a']--;
            sCnt[s.charAt(i) - 'a']++;
            if (true == compare(sCnt, pCnt)) {
                res.add(i - pLen + 1);
            }
        }
        return res;
    }
}