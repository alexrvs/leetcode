class Solution {
public:
    bool detectCapitalUse(string word) {
        int size = word.size();
        bool expectCap = true;
        if (size == 0) return false;
        if (word[0] >= 'a' && word[0] <= 'z') {
            expectCap = false;
        }
        for (int i = 1; i < size; i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                if (expectCap == true && i == 1) {
                    expectCap = false;
                } else if (expectCap == true) {
                    return false;
                }
            } else {
                if (expectCap == false) {
                    return false;
                }
            }
        }
        return true;
    }
};