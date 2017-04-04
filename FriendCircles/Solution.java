public class Solution {
    
    private void markVisit(int[][] M, int r, Set<Integer> visit) {
        visit.add(m);
        for (int i = 0; i < M[0].length; i++) {
            if (1 == M[m][i] && !visit.contains(key)) {
                markVisit(M, i, visit);
            }
        }
        return;
    }
    
    public int findCircleNum(int[][] M) {
        int r = M.length;
        int res = 0;
        Set<Integer> visit = new HashSet<Integer>();
        for (int i = 0; i < r; i++) {
            if (!visit.contains(i)) {
                res++;
                markVisit(M, i, visit);
            }
        }
        return res;
    }
}