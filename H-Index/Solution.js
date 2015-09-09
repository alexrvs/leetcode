/**
 * @param {number[]} citations
 * @return {number}
 */
var hIndex = function(citations) {
    var size = citations.length;
    var cnt = [];
    for (var i = 0; i < size+1; i++) {
        cnt[i] = 0;
    }
    for (i = 0; i < size; i++) {
        if (citations[i] >= size) {
            cnt[size]++;
        } else {
            cnt[citations[i]]++;
        }
    }
    if (cnt[size] >= size) return size;
    for (i = size - 1; i >= 0; i--) {
        cnt[i] += cnt[i+1];
        if (cnt[i] >= i) {
            return i;
        }
    }
    return 0;
};
