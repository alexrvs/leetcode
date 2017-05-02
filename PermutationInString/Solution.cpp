class Solution {
private:
    bool compareCharCnts(vector<int>& charCnts1, vector<int>& charCnts2) {
        for (int i = 0; i < 26; i++) {
            if (charCnts1[i] != charCnts2[i]) {
                return false;
            }
        }
        return true;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.size();
        int s2Size = s2.size();
        if (s2Size < s1Size) return false;
        vector<int> s1CharCnts(26, 0);
        vector<int> s2CharCnts(26, 0);
        for (int i = 0; i < s2Size; i++) {
            if (i < s1Size) {
                s1CharCnts[s1[i] - 'a']++;
            }
            s2CharCnts[s2[i] - 'a']++;
            if (i >= s1Size) {
                s2CharCnts[s2[i - s1Size] - 'a']--;
            }
            if (i >= s1Size - 1) {
                
                if (true == compareCharCnts(s1CharCnts, s2CharCnts)) {
                    return true;
                }
            }
        }
        return false;
    }
}