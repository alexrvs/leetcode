int trap(int* height, int heightSize) {
    int* water = (int*) malloc(heightSize * sizeof(int));
    int max = 0;
    int sum = 0;
    for (int i = 0; i < heightSize; i++) {
        max = max > height[i] ? max : height[i];
        water[i] = max - height[i];
    }
    max = 0;
    for (int i = heightSize - 1; i >= 0; i--) {
        max = max > height[i] ? max : height[i];
        int h = max - height[i];
        sum += water[i] < h ? water[i] : h;
    }
    free(water);
    return sum;
}
