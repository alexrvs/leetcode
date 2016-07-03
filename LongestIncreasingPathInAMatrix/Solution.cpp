class Solution {
private:
    int findPath(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& pathLen, int pre) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] >= pre) return 0;
        if (pathLen[i][j] == 0) {
            int len = 0;
            int max = 0;
            len = findPath(i - 1, j, matrix, pathLen, matrix[i][j]);
            max = max > len ? max : len;
            len = findPath(i + 1, j, matrix, pathLen, matrix[i][j]);
            max = max > len ? max : len;
            len = findPath(i, j - 1, matrix, pathLen, matrix[i][j]);
            max = max > len ? max : len;
            len = findPath(i, j + 1, matrix, pathLen, matrix[i][j]);
            max = max > len ? max : len;
            pathLen[i][j] = max + 1;
        }
        return pathLen[i][j];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<vector<int> > pathLen(m, vector<int>(n, 0));
        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int l = findPath(i, j, matrix, pathLen, INT_MAX );
                max = l > max ? l : max;
            }
        }
        return max;
    }
};
