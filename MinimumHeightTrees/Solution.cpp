class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        vector<vector<int> > depends(n, vector<int>() );
        vector<int> degree(n, 0);
        vector<int> layer(n, 0);
        int l = 1;
        for (auto e : edges) {
            int n1 = e.first;
            int n2 = e.second;
            degree[n1] += 1;
            degree[n2] += 1;
            depends[n1].push_back(n2);
            depends[n2].push_back(n1);
        }
        bool removed = false;
        while (true) {
            removed = false;
            for (int i = 0; i < n; i++) {
                if (degree[i] == 1) {
                    removed = true;
                    layer[i] = l;
                }
            }
            if (removed == false) break;
            for (int i = 0; i < n; i++) {
                if (layer[i] == l) {
                    degree[i] -= 1;
                    for (int j : depends[i]) {
                        if (degree[j] > 0) degree[j] -= 1;
                    }
                }
            }
            l++;
        }
        vector<int> res;
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (layer[i] == 0) layer[i] = l;
            max = max > layer[i] ? max : layer[i];
        }
        for (int i = 0; i < n; i++) {
            if (layer[i] == max) res.push_back(i);
        }
        return res;
    }
};
