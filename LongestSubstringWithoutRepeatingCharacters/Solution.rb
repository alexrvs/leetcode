# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
  start = 0
  len = 0
  max = 0
  s_len = s.length
  if s_len == 0
    return 0
  end
  i = 1
  while i < s_len
    j = start
    while j < i
      if s[j] == s[i]
        len = i - start
        if max < len
          max = len
        end
        start = j+1
        break
      end
      j += 1
    end
    i += 1
  end
  len = s_len - start
  if max < len
    max = len
  end
  return max
end

str1 = "a"
puts(length_of_longest_substring(str1))
