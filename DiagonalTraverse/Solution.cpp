class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int dir = 1;
        int i = 0;
        int j = 0;
        vector<int> res;
        int r = matrix.size();
        if (r == 0) return res;
        int c = matrix[0].size();
        if (c == 0) return res;
        while (i >= 0 && i < r && j >= 0 && j < c) {
            res.push_back(matrix[i][j]);
            if (dir == 1) {
                if (j == c - 1) {
                    i++;
                    dir = -dir;
                } else if (i == 0) {
                    j++;
                    dir = -dir;
                } else {
                    i--;
                    j++;
                }
            } else {
                if (i == r - 1) {
                    j++;
                    dir = -dir;
                } else if (j == 0) {
                    i++;
                    dir = -dir;
                } else {
                    i++;
                    j--;
                }
            }
        }
        return res;
    }
};