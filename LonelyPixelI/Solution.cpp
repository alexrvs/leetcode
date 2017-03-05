class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int r = picture.size();
        if (r == 0) return 0;
        int c = picture[0].size();
        if (c == 0) return 0;
        vector<int> rowCnt(r, 0);
        vector<int> colCnt(c, 0);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (picture[i][j] == 'B') {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (picture[i][j] == 'B' && rowCnt[i] == 1 && colCnt[j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};