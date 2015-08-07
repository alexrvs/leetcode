#!/usr/bin/env python

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        numMap={}
        for (i, num) in enumerate(nums):
            lookup = target - num
            if lookup in numMap:
                return (numMap[lookup] + 1, i + 1)
            numMap[num] = i
