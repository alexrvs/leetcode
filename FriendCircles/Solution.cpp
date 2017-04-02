class Solution {
private:
    void markVisit(vector<vector<int>>& M, int m, unordered_set<int>& visit) {
        visit.insert(m);
        for (int i = 0; i < M[0].size(); i++) {
            if (1 == M[m][i] && visit.find(i) == visit.end()) {
                markVisit(M, i, visit);
            }
        }
        return;
    }

public:
    int findCircleNum(vector<vector<int>>& M) {
        int r = M.size();
        int res = 0;
        unordered_set<int> visit;
        for (int i = 0; i < r; i++) {
            if (visit.find(i) == visit.end()) {
                res++;
                markVisit(M, i, visit);
            }
        }
        return res;
    }
};