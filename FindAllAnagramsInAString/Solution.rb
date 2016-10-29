def compare(sCnt, pCnt)
    pCnt.length.times do | i |
        return false if sCnt[i] != pCnt[i]
    end
    return true
end

# @param {String} s
# @param {String} p
# @return {Integer[]}
def find_anagrams(s, p)
    sLen = s.length
    pLen = p.length
    res = []
    return res if sLen < pLen
    sCnt = Array.new(26, 0)
    pCnt = Array.new(26, 0)
    pLen.times do | i |
        pCnt[p[i].ord - 'a'.ord] += 1
    end
    pLen.times do | i |
        sCnt[s[i].ord - 'a'.ord] += 1
    end
    res << 0 if true == compare(sCnt, pCnt)
    pLen.upto(sLen - 1) do | i |
        sCnt[s[i - pLen].ord - 'a'.ord] -= 1
        sCnt[s[i].ord - 'a'.ord] += 1
        res << i - pLen + 1 if true == compare(sCnt, pCnt)
    end
    return res
end