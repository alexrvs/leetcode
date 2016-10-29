class Solution {
private:
    bool compare(vector<int> sCnt, vector<int> pCnt) {
        for (int i = 0; i < pCnt.size(); i++) {
            if (sCnt[i] != pCnt[i]) return false;
        }
        return true;
    }
    
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        vector<int> res;
        if (sLen < pLen) return res;
        vector<int> pCnt(26, 0);
        vector<int> sCnt(26, 0);
        for (int i = 0; i < pLen; i++) {
            pCnt[p[i] - 'a']++;
        }
        for (int i = 0; i < pLen; i++) {
            sCnt[s[i] - 'a']++;
        }
        if (true == compare(sCnt, pCnt)) {
            res.push_back(0);
        }
        for (int i = pLen; i < sLen; i++) {
            sCnt[s[i - pLen] - 'a']--;
            sCnt[s[i] - 'a']++;
            if (true == compare(sCnt, pCnt)) {
                res.push_back(i - pLen + 1);
            }
        }
        return res;
    }
};