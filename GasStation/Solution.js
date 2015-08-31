/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    var start = -1;
    var tank = 0;
    var cur = -1;
    for (var i = 0; i < gas.length*2; i++) {
        cur = i%gas.length;
        if (cur == start) return start;
        tank += gas[cur] - cost[cur];
        if (tank >= 0) {
            if (start == -1) start = cur;
        } else {
            start = -1;
            tank = 0;
        }
    }
    return -1;
};
