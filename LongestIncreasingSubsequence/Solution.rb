def search(seq, l, r, target)
    while l < r do
        m = l + (r - l) / 2
        if seq[m] < target then
            l = m + 1
        else
            r = m
        end
    end
    return l
end

# @param {Integer[]} nums
# @return {Integer}
def length_of_lis(nums)
    n = nums.length
    return 0 if n == 0
    seq = Array.new(n)
    seqLen = 0
    nums.each do | num |
        pos = search(seq, 0, seqLen, num)
        seq[pos] = num
        seqLen += 1 if pos == seqLen
    end
    return seqLen
end
