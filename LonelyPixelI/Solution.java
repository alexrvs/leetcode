public class Solution {
    public int findLonelyPixel(char[][] picture) {
        int r = picture.length;
        if (r == 0) return 0;
        int c = picture[0].length;
        if (c == 0) return 0;
        int[] rowCnt = new int[r];
        int[] colCnt = new int[c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (picture[i][j] == 'B') {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (picture[i][j] == 'B' && rowCnt[i] == 1 && colCnt[j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}