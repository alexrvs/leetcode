/**
 * @param {number[]} citations
 * @return {number}
 */
var hIndex = function(citations) {
    var size = citations.length;
    for (var i = 0; i < size; i++) {
        var cnt = size - i;
        if (citations[i] >= cnt) {
            return cnt;
        }
    }
    return 0;
};
