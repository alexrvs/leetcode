class Solution {
private:
    vector<int> split(string s) {
        vector<int> ans;
        int tmp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') {
                ans.push_back(tmp);
                tmp = 0;
            } else {
                tmp = tmp * 10 + s[i] - '0';
            }
        }
        ans.push_back(tmp);
        vector<int>::iterator it = ans.end() - 1;
        while(*it == 0) {
            ans.erase(it);
            it = ans.end() - 1;
        }
        return ans;
    }

public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        int len = min(v1.size(), v2.size());
        for (int i = 0; i < len; i++) {
            if (v1[i] > v2[i]) return 1;
            else if (v1[i] < v2[i]) return -1;
        }
        if (v1.size() > v2.size()) return 1;
        if (v1.size() < v2.size()) return -1;
        return 0;
    }
};