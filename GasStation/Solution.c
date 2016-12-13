int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int tank = 0;
    int start = -1;
    int cur = 0;
    for (int i = 0; i < gasSize * 2; i++) {
        cur = i % gasSize;
        if (cur == start) return start;
        tank += gas[cur] - cost[cur];
        if (tank >= 0) {
            if (-1 == start) {
                start = cur;
            }
        } else {
            start = -1;
            tank = 0;
        }
    }
    return -1;
}