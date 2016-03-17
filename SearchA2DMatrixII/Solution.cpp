class Solution {
private:
    bool searchRow(vector<int>& row, int target) {
        int size = row.size();
        int l = 0;
        int r = size;
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (row[m] < target) {
                l = m + 1;
            } else if (row[m] == target) {
                return true;
            } else {
                r = m;
            }
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size();
        int l = 0;
        int r = size;
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (matrix[m][0] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        for (int i = l - 1; i >= 0; i--) {
            if (searchRow(matrix[i], target) == true) {
                cout << matrix[i][0] << endl;
                return true;
            }
        }
        return false;
    }
};
