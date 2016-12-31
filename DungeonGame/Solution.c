int calculateMinimumHP(int** dungeon, int dungeonRowSize, int dungeonColSize) {
    if (dungeonRowSize == 0 || dungeonColSize == 0) return 0;
    int** needHP = (int**) malloc(dungeonRowSize * sizeof(int*));
    for (int i = dungeonRowSize - 1; i >= 0; i--) {
        needHP[i] = (int*) malloc(dungeonColSize * sizeof(int));
        for (int j = dungeonColSize - 1; j >= 0; j--) {
            if (i == dungeonRowSize - 1 && j == dungeonColSize - 1) {
                needHP[i][j] = 1 - dungeon[i][j];
                if (needHP[i][j] < 1) needHP[i][j] = 1;
            } else if (i == dungeonRowSize - 1) {
                needHP[i][j] = needHP[i][j + 1] - dungeon[i][j];
                if (needHP[i][j] < 1) needHP[i][j] = 1;
            } else if (j == dungeonColSize - 1) {
                needHP[i][j] = needHP[i + 1][j] - dungeon[i][j];
                if (needHP[i][j] < 1) needHP[i][j] = 1;
            } else {
                int right = needHP[i][j + 1] - dungeon[i][j];
                int down = needHP[i + 1][j] - dungeon[i][j];
                if (right < down) needHP[i][j] = right;
                else needHP[i][j] = down;
                if (needHP[i][j] < 1) needHP[i][j] = 1;
            }
        }
    }
    int res = needHP[0][0];
    for (int i = 0; i < dungeonRowSize; i++) {
        free(needHP[i]);
    }
    free(needHP);
    return res;
}