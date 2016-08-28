public class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int eSize = prerequisites.length;
        int[] in = new int[numCourses];
        int[] out = new int[numCourses];
        int[][] depend = new int[numCourses][numCourses];
        for (int i = 0; i < eSize; i++) {
            int from = prerequisites[i][0];
            int to = prerequisites[i][1];
            if (depend[to][from] != 1) {
                in[to]++;
                out[from]++;
                depend[to][from] = 1;
            }
        }
        boolean changed = false;
        int[] res = new int[numCourses];
        int[] used = new int[numCourses];
        int resSize = 0;
        while (true) {
            changed = false;
            for (int i = 0; i < numCourses; i++) {
                if (out[i] == 0 && in[i] > 0) {
                    for (int j = 0; j < numCourses; j++) {
                        if (depend[i][j] == 1) {
                            changed = true;
                            out[j]--;
                            in[i]--;
                            depend[i][j] = 0;

                        }
                    }
                    res[resSize++] = i;
                    used[i] = 1;
                }
            }
            if (changed == false) break;
        }
        for (int i = 0; i < numCourses; i++) {
            if (out[i] > 0) return new int[0];
            if (used[i] == 0) {
                res[resSize++] = i;
                used[i] = 1;
            }
        }
        return res;
    }
}
