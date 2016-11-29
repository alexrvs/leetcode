public class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int gi = g.length - 1;
        int si = s.length - 1;
        int cnt = 0;
        while (gi >= 0 && si >= 0) {
            if (g[gi] <= s[si]) {
                cnt++;
                si--;
            }
            gi--;
        }
        return cnt;
    }
}