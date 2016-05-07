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

void swap(char* s, char* t) {
    char c = *s;
    *s = *t;
    *t = c;
    return;
}

char* reverseVowels(char* s) {
    int l = 0;
    int r = strlen(s) - 1;
    while (l < r) {
        if (isVowel(s[l]) && isVowel(s[r]) ) {
            swap(s + l, s + r);
            l++;
            r--;
        } else {
            if (!isVowel(s[l])) l++;
            if (!isVowel(s[r])) r--;
        }
    }
    return s;
}
