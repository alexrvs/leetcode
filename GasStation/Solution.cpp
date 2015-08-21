class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int tank = 0;
    int num = gas.size();
    int start = -1;
    for (int i = 0; i < 2*num; i++) {
      int cur = i%num;
      if (cur == start)
      return start;
      tank += gas[cur]-cost[cur];
      if (tank >= 0) {
        if (start == -1)
        start = cur;
      } else {
        start = -1;
        tank = 0;
      }
    }
    return -1;
  }
};
