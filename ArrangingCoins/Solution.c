int arrangeCoins(int n) {
    if (n == 0) return 0;
    int layer = 1;
    while (n >= layer) {
        n -= layer;
        layer++;
    }
    return layer - 1;
}