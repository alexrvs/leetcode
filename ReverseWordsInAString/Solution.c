void reverse(char *s, int i, int j) {
    char temp = 0;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    return;
}

void removeSpaces(char *s) {
    int size = strlen(s);
    int start = 0;
    while (s[start] == ' ') start++;
    int end = size - 1;
    while (s[end] == ' ') end--;
    int cur = 0;
    for (int i = start; i <= end; i++) {
        if (!(s[i] == ' ' && cur > 0 && s[cur - 1] == ' ') ){
            s[cur] = s[i];
            cur++;
        }
    }
    s[cur] = '\0';
    return;
}

void reverseWords(char *s) {
    int size = strlen(s);
    reverse(s, 0, size - 1);
    int start = 0;
    int end = 0;
    for (int i = 0; i < size; i++) {
        if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
            start = i;
        }
        if ((i == size - 1 || s[i + 1] == ' ') && s[i] != ' ') {
            end = i;
            reverse(s, start, end);
        }
    }
    removeSpaces(s);
    return;
}