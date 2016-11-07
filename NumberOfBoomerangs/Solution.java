public class Solution {
    private int distance(int[][] points, int i, int j) {
        int a = points[i][0] - points[j][0];
        int b = points[i][1] - points[j][1];
        return a * a + b * b;
    }
    
    public int numberOfBoomerangs(int[][] points) {
        int cnt = 0;
        for (int i = 0; i < points.length - 2; i++) {
            for (int j = i + 1; j < points.length - 1; j++) {
                for (int k = j + 1; k < points.length; k++) {
                    int dij = distance(points, i, j);
                    int djk = distance(points, j, k);
                    int dik = distance(points, i, k);
                    if (dij == djk) cnt += 2;
                    if (djk == dik) cnt += 2;
                    if (dij == dik) cnt += 2;
                }
            }
        }
        return cnt;
    }
}