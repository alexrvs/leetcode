class Solution {
private:
    void expand(vector<vector<bool> >& map, vector<vector<bool> >& visited, vector<vector<int> >& matrix, int i, int j) {
        int m = map.size();
        int n = map[0].size();
        
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
    
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int> > res;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        if (n == 0) return res;
        vector<vector<bool> > toPacific(m, vector<bool>(n, false));
        vector<vector<bool> > toAtlantic(m, vector<bool>(n, false));
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
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
                    pair<int, int> pair(i, j);
                    res.push_back(pair);
                }
            }
        }
        return res;
    }
};