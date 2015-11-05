class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == i) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += (triangle[i - 1][j] < triangle[i - 1][j - 1] ? triangle[i - 1][j] : triangle[i - 1][j - 1]);
                }
            }
        }
        for (int i = 1; i < r; i++) {
            if (triangle[r - 1][0] > triangle[r - 1][i]) {
                triangle[r - 1][0] = triangle[r - 1][i];
            }
        }
        return triangle[r - 1][0];
    }
};
