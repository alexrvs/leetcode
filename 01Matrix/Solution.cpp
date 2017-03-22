class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dist(r, vector<int>(c, r + c - 2));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    int a = (i > 0) ? (dist[i - 1][j] + 1) : (r + c);
                    int b = (j > 0) ? (dist[i][j - 1] + 1) : (r + c);
                    dist[i][j] = min(dist[i][j], min(a, b));
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = c - 1; j >= 0; j--) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    int a = (i > 0) ? (dist[i - 1][j] + 1) : (r + c);
                    int b = (j < c - 1) ? (dist[i][j + 1] + 1) : (r + c);
                    dist[i][j] = min(dist[i][j], min(a, b));
                }
            }
        }
        for (int i = r - 1; i >= 0; i--) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    int a = (i < r - 1) ? (dist[i + 1][j] + 1) : (r + c);
                    int b = (j > 0) ? (dist[i][j - 1] + 1) : (r + c);
                    dist[i][j] = min(dist[i][j], min(a, b));
                }
            }
        }
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    int a = (i < r - 1) ? (dist[i + 1][j] + 1) : (r + c);
                    int b = (j < c - 1) ? (dist[i][j + 1] + 1) : (r + c);
                    dist[i][j] = min(dist[i][j], min(a, b));
                }
            }
        }
        return dist;
    }
};