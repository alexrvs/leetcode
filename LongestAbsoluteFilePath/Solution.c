int lengthLongestPath(char* input) {
    int size = strlen(input);
    int* layer = (int*) malloc(size * sizeof(int));
    memset(layer, 0, size * sizeof(int));
    int curLen = 0;
    int curLayer = 0;
    int maxLen = 0;
    bool isFile = false;
    for (int i = 0; i <= size; i++) {
        if (i == size || input[i] == '\n') {
            layer[curLayer] = curLen;
            if (isFile == true) {
                int pathLen = 0;
                for (int j = 0; j <= curLayer; j++) {
                    pathLen += layer[j];
                }
                pathLen += curLayer;
                maxLen = maxLen > pathLen ? maxLen : pathLen;
            }
            isFile = false;
            curLayer = 0;
            curLen = 0;
        } else if (input[i] == '\t') {
            curLayer++;
        } else {
            curLen++;
            if (input[i] == '.') {
                if (i + 1 < size && input[i + 1] != '\t' && input[i + 1] != '\n') isFile = true;
            }
        }
    }
    return maxLen;
}
