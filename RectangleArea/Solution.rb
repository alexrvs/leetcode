# @param {Integer} a
# @param {Integer} b
# @param {Integer} c
# @param {Integer} d
# @param {Integer} e
# @param {Integer} f
# @param {Integer} g
# @param {Integer} h
# @return {Integer}
def compute_area(a, b, c, d, e, f, g, h)
    area1 = (c - a) * (d - b)
    area2 = (g - e) * (h - f)
    inL = a > e ? a : e
    inR = c < g ? c : g
    inB = b > f ? b : f
    inT = d < h ? d : h
    inW = inR > inL ? inR - inL : 0
    inH = inT > inB ? inT - inB : 0
    return area1 + area2 - (inW * inH)
end
