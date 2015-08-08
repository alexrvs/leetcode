#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int size = numbers.size();
        int sum = 0;
        unordered_map<int, int> numMap;
        vector<int> res;
        
        for(int i = 0; i < size; i++) {
            if (numMap.find(numbers[i]) == numMap.end())
                numMap[numbers[i]] = i;
            int v = target - numbers[i];
            if (numMap.find(target-numbers[i]) != numMap.end()) {
                if (numMap[v] != i) {
                    res.push_back(numMap[target-numbers[i]]+1);
                    res.push_back(i+1);
                    break;
                }
            }
        }

        return res;
    }
};
