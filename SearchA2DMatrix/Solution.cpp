class Solution {
private:
    int search(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size();
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (matrix[m][0] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return r - 1;
    }

    bool searchRow(vector<int>& row, int target) {
        int l = 0;
        int r = row.size();
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
        if (matrix.size() == 0) return false;
        int i = search(matrix, target);
        if (i < 0) return false;
        return searchRow(matrix[i], target);
    }
};
