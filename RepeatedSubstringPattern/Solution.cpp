class Solution {
private:
    bool isSame(string str, int pl, int s) {
        for (int i = 0; i < pl; i++) {
            if (str[i] != str[s + i]) return false;
        }
        return true;
    }
    
public:
    bool repeatedSubstringPattern(string str) {
        int size = str.size();
        for (int l = 1; l <= size / 2; l++) {
            if (size % l == 0) {
                bool isRepeated = true;
                for (int s = l; s < size; s += l) {
                    if (false == isSame(str, l, s)) {
                        isRepeated = false;
                        break;
                    }
                }
                if (isRepeated == true) return true;
            }
        }
        return false;
    }
};