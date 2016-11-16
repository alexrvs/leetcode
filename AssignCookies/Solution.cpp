class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = g.size() - 1;
        int si = s.size() - 1;
        int cnt = 0;
        while (gi >= 0 && si >= 0) {
            if (g[gi] <= s[si])  {
                cnt++;
                si--;
            }
            gi--;
        }
        return cnt;
    }
};