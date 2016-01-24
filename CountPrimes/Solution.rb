# @param {Integer} n
# @return {Integer}
def count_primes(n)
    return 0 if n <= 2
    return n - 2 if n < 5
    l = 0
    while l * l < n do l += 1 end
    i = 2
    nums = Array.new(n, 0)
    while i <= l do
        if nums[i] != 1 then
            j = 2 * i
            while j < n do
                nums[j] = 1
                j += i
            end
        end
        i += 1
    end
    cnt = 0
    2.upto(n - 1) do |num|
        cnt += 1 if nums[num] != 1
    end
    return cnt    
end
