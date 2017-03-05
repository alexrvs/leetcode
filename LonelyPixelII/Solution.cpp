class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int r = picture.size();
        if (r == 0) return 0;
        int c = picture[0].size();
        if (c == 0) return 0;
        unordered_map<int, set<int>> rows;
        unordered_map<int, set<int>> cols;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (picture[i][j] == 'B') {
                    rows[i].insert(j);
                    cols[j].insert(i);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (picture[i][j] == 'B' && rows[i].size() == N && cols[j].size() == N) {
                    int lonely = 1;
                    for (int r : cols[j]) {
                        if (rows[i] != rows[r]) {
                            lonely = 0;
                            break;
                        }
                    }
                    cnt += lonely;
                }
            }
        }
        return cnt;
    }
};