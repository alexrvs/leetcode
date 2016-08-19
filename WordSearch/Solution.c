bool helper(char** board, int boardRowSize, int boardColSize, int i, int j, char* word, int idx, int wordSize) {
    char c;
    if (idx == wordSize) return true;
    else if (idx == 0) {
        for (i = 0; i < boardRowSize; i++) {
            for (j = 0; j < boardColSize; j++) {
                if (board[i][j] == word[idx]) {
                    c = word[idx];
                    board[i][j] = 0;
                    bool match = helper(board, boardRowSize, boardColSize, i, j, word, idx + 1, wordSize);
                    board[i][j] = c;
                    if (match == true) return true;
                }
            }
        }
    } else {
        if (i - 1 >= 0 && board[i - 1][j] == word[idx]) {
            c = word[idx];
            board[i - 1][j] = 0;
            bool match = helper(board, boardRowSize, boardColSize, i - 1, j, word, idx + 1, wordSize);
            board[i - 1][j] = c;
            if (match == true) return true;
        }
        if (i + 1 < boardRowSize && board[i + 1][j] == word[idx]) {
            c = word[idx];
            board[i + 1][j] = 0;
            bool match = helper(board, boardRowSize, boardColSize, i + 1, j, word, idx + 1, wordSize);
            board[i + 1][j] = c;
            if (match == true) return true;
        }
        if (j - 1 >= 0 && board[i][j - 1] == word[idx]) {
            c = word[idx];
            board[i][j - 1] = 0;
            bool match = helper(board, boardRowSize, boardColSize, i, j - 1, word, idx + 1, wordSize);
            board[i][j - 1] = c;
            if (match == true) return true;
        }
        if (j + 1 < boardColSize && board[i][j + 1] == word[idx]) {
            c = word[idx];
            board[i][j + 1] = 0;
            bool match = helper(board, boardRowSize, boardColSize, i, j + 1, word, idx + 1, wordSize);
            board[i][j + 1] = c;
            if (match == true) return true;
        }
    }
    return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    int wordSize = strlen(word);
    return helper(board, boardRowSize, boardColSize, 0, 0, word, 0, wordSize);
}
