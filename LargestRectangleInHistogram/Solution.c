struct Node {
    int h;
    int l;
};

int largestRectangleArea(int* heights, int heightsSize) {
    int size = heightsSize;
    struct Node* stack = (struct Node*) malloc(size * sizeof(struct Node));
    int stackSize = 0;
    int maxArea = 0;
    for (int i = 0; i < size; i++) {
        int curH = heights[i];
        if (stackSize == 0 || stack[stackSize - 1].h < curH) {
            stack[stackSize].h = curH;
            stack[stackSize].l = 1;
            stackSize++;
        } else {
            int curL = 0;
            int area = 0;
            while (stackSize != 0 && stack[stackSize - 1].h >= curH) {
                printf("%d\n", __LINE__);
                curL += stack[stackSize - 1].l;
                area = stack[stackSize - 1].h * curL;
                if (maxArea < area) maxArea = area;
                stackSize--;
            }
            stack[stackSize].h = curH;
            stack[stackSize].l = curL + 1;
            stackSize++;
        }
    }
    int curL = 0;
    while (stackSize != 0) {
        curL += stack[stackSize - 1].l;
        int area = curL * stack[stackSize - 1].h;
        stackSize--;
        if (maxArea < area) maxArea = area;
    }
    free(stack);
    return maxArea;
}