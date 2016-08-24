class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> cnt;
        vector<string> res;
        for (int i = 0; i < 10; i++) {
            for (int j = i; j + 10 <= s.size(); j += 10) {
                string sub = s.substr(j, 10);
                int c = 0;
                if (cnt.find(sub) != cnt.end()) {
                    c = cnt[sub];
                }
                cnt[sub] = c + 1;
            }
        }
        for (auto c : cnt) {
            if (c.second > 1) res.push_back(c.first);
        }
        return res;
    }
};
