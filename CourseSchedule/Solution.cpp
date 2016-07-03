class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int> > depends(n, vector<int>() );
        vector<int> out(n, 0);
        vector<int> in(n, 0);
        for (auto e : prerequisites) {
            int n1 = e.first;
            int n2 = e.second;
            out[n1] += 1;
            in[n2] += 1;
            depends[n2].push_back(n1);
        }
        bool removed = false;
        while (true) {
            removed = false;
            for (int i = 0; i < n; i++) {
                if (out[i] == 0 && in[i] != 0) {
                    for (int j = 0; j < depends[i].size(); j++) {
                        out[depends[i][j]] -= 1;
                        in[i] -= 1;
                    }
                    removed = true;
                }
            }
            if (removed == false) break;
        }
        for (int i = 0; i < n; i++) {
            if (out[i] != 0) return false;
        }
        return true;
    }
};
