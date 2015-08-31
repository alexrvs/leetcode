# @param {Integer[]} gas
# @param {Integer[]} cost
# @return {Integer}
def can_complete_circuit(gas, cost)
    start = -1
    tank = 0
    i = 0
    while i < 2*gas.length
        cur = i%gas.length
        return start if cur == start
        tank += gas[cur] - cost[cur]
        if tank >= 0
            start = cur if start == -1
        else
            start = -1
            tank = 0
        end
        i += 1
    end
    return -1
end
