# @param {Integer[]} citations
# @return {Integer}
def h_index(citations)
    l = citations.length
    cnt = Array.new(l + 1) {0}
    citations.each do |c|
        if c > l - 1
            cnt[l] += 1
        else
            cnt[c] += 1
        end
    end
    cnt.to_enum.with_index.reverse_each do |c, i|
        cnt[i] += cnt[i+1] if i < l
        if cnt[i] >= i
            return i
        end
    end
    return 0
end
