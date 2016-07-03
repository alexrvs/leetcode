class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int> > depends(n, vector<int>() );
        vector<int> res;
        vector<int> out(n, 0);
        vector<int> removed(n, 0);
        for (auto e : prerequisites) {
            int n1 = e.first;
            int n2 = e.second;
            out[n1] += 1;
            depends[n2].push_back(n1);
        }
        bool changed = false;
        while (true) {
            changed = false;
            for (int i = 0; i < n; i++) {
                if (out[i] == 0 && removed[i] != 1) {
                    res.push_back(i);
                    removed[i] = 1;
                    for (int j = 0; j < depends[i].size(); j++) {
                        out[depends[i][j]] -= 1;
                    }
                    changed = true;
                }
            }
            if (changed == false) break;
        }
        if (res.size() < n) return vector<int>();
        return res;
    }
};
