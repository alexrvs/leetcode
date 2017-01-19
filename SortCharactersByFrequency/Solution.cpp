class Solution {
public:
    string frequencySort(string s) {
        int lower[256];
        memset(lower, 0, 256 * sizeof(int));
        for (int i = 0; i < s.size(); i++) {
            lower[s[i]]++;
        }
        vector<pair<int, char> > res;
        for (int i = 0; i < 256; i++) {
            if (lower[i] > 0) {
                res.push_back(pair<int, char>(lower[i], i));
            }
        }
        sort(res.begin(), res.end());
        string resStr = "";
        int size = res.size();
        for (int i = size - 1; i >= 0; i--) {
            int cnt = res[i].first;
            char c = res[i].second;
            for (int j = 0; j < cnt; j++) {
                resStr += c;
            }
        }
        return resStr;
    }
};