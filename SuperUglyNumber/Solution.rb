# @param {Integer} n
# @param {Integer[]} primes
# @return {Integer}
def nth_super_ugly_number(n, primes)
    k = primes.length
    idx = Array.new(k, 0)
    un = Array.new(n + 1, 1)
    1.upto(n - 1) do | i |
        primes.each_with_index do | p, j |
            num = p * un[idx[j]]
            un[i] = num if un[i] == 1 || num < un[i]
        end
        primes.each_with_index do | p, j |
            num = p * un[idx[j]]
            idx[j] += 1 if un[i] == num
        end
    end
    return un[n - 1]
end
