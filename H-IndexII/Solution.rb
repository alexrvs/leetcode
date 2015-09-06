# @param {Integer[]} citations
# @return {Integer}
def h_index(citations)
    citations.each_with_index do | x, i |
        cnt = citations.length - i
        if x >= cnt
            return cnt
        end
    end
    return 0
end
