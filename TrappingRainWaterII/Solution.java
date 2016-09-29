public class Solution {

    class Cell implements Comparable {
        int i;
        int j;
        int h;

        public Cell(int i, int j, int h) {
            this.i = i;
            this.j = j;
            this.h = h;
        }

        public int compareTo(Object obj) {
            Cell c = (Cell) obj;
            return this.h - c.h;
        }
    }

    public int trapRainWater(int[][] heightMap) {
        int h = heightMap.length;
        if (h < 3) return 0;
        int w = heightMap[0].length;
        if (w < 3) return 0;
        boolean[][] visited = new boolean[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                visited[i][j] = false;
            }
        }
        PriorityQueue<Cell> queue = new PriorityQueue<Cell>();
        for (int i = 0; i < h; i++) {
            visited[i][0] = true;
            visited[i][w - 1] = true;
            queue.offer(new Cell(i, 0, heightMap[i][0]));
            queue.offer(new Cell(i, w - 1, heightMap[i][w - 1]));
        }
        for (int j = 0; j < w; j++) {
            visited[0][j] = true;
            visited[h - 1][j] = true;
            queue.offer(new Cell(0, j, heightMap[0][j]));
            queue.offer(new Cell(h - 1, j, heightMap[h - 1][j]));
        }
        int sum = 0;
        int[][] dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!queue.isEmpty()) {
            Cell cur = queue.poll();
            for (int k = 0; k < dir.length; k++) {
                int ni = cur.i + dir[k][0];
                int nj = cur.j + dir[k][1];
                if (ni >= 0 && ni < h &&
                    nj >= 0 && nj < w &&
                    visited[ni][nj] == false) {
                    int nh = heightMap[ni][nj];
                    if (cur.h > nh) {
                        sum += cur.h - nh;
                        nh = cur.h;
                    }
                    visited[ni][nj] = true;
                    queue.offer(new Cell(ni, nj, nh));
                }
            }
        }
        return sum;
    }
}
