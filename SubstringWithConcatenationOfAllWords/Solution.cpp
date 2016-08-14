class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        int size = words.size();
        for (int i = 0; i < size; i++) {
            cnt[words[i]]++;
        }
        int wlen = words[0].size();
        int length = s.size();
        unordered_map<string, int> seen;
        vector<int> res;
        for (int i = 0; i < length - size * wlen + 1; i++) {
            seen.clear();
            int j = 0;
            for (; j < size; j++) {
                string w = s.substr(i + j * wlen, wlen);
                if (cnt.find(w) != cnt.end()) {
                    seen[w]++;
                } else break;
                if (seen[w] > cnt[w]) break;
            }
            if (j == size) res.push_back(i);
        }
        return res;
    }
};
