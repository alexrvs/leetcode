class Solution {
private:
    bool isVowel(char c) {
        switch(c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
        }
        return false;
    }

    void swap(string& s, int i, int j) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        return;
    }

public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (isVowel(s[l]) && isVowel(s[r]) ) {
                swap(s, l, r);
                l++;
                r--;
            } else {
                if (!isVowel(s[l])) l++;
                if (!isVowel(s[r])) r--;
            }
        }
        return s;
    }
};
