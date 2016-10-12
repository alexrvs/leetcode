public class Solution {
    
    private void expand(boolean[][] map, boolean[][] visited, int[][] matrix, int i, int j) {
        int m = map.length;
        int n = map[0].length;
        
        for (int ni = i - 1; ni <= i + 1; ni += 2) {
            if (ni >= 0 && ni < m && visited[ni][j] == false && matrix[ni][j] >= matrix[i][j]) {
                visited[ni][j] = true;
                map[ni][j] = true;
                expand(map, visited, matrix, ni, j);
            }
        }

        for (int nj = j - 1; nj <= j + 1; nj += 2) {
            if (nj >= 0 && nj < n && visited[i][nj] == false && matrix[i][nj] >= matrix[i][j]) {
                visited[i][nj] = true;
                map[i][nj] = true;
                expand(map,visited, matrix, i, nj);
            }
        }
    }
    
    public List<int[]> pacificAtlantic(int[][] matrix) {
        List<int[]> res = new ArrayList<int[]>();
        int m = matrix.length;
        if (m == 0) return res;
        int n = matrix[0].length;
        if (n == 0) return res;
        boolean[][] toPacific = new boolean[m][n];
        boolean[][] toAtlantic = new boolean[m][n];
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                toPacific[i][j] = false;
                toAtlantic[i][j] = false;
                visited[i][j] = false;
                if (i == 0 || j == 0) {
                    toPacific[i][j] = true;
                }
                if (i == m - 1 || j == n - 1) {
                    toAtlantic[i][j] = true;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false && toPacific[i][j] == true) {
                    expand(toPacific, visited, matrix, i, j);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (visited[i][j] == false && toAtlantic[i][j] == true) {
                    expand(toAtlantic, visited, matrix, i, j);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (toPacific[i][j] == true && toAtlantic[i][j]) {
                    int[] pair = new int[2];
                    pair[0] = i;
                    pair[1] = j;
                    res.add(pair);
                }
            }
        }
        return res;
    }
}