/**
 * @param {number} A
 * @param {number} B
 * @param {number} C
 * @param {number} D
 * @param {number} E
 * @param {number} F
 * @param {number} G
 * @param {number} H
 * @return {number}
 */
var computeArea = function(A, B, C, D, E, F, G, H) {
    var area1 = (C - A) * (D - B);
    var area2 = (G - E) * (H - F);
    var inL = A > E ? A : E;
    var inR = C < G ? C : G;
    var inB = B > F ? B : F;
    var inT = D < H ? D : H;
    var inW = inR > inL ? inR - inL : 0;
    var inH = inT > inB ? inT - inB : 0;
    var sum = area1 + area2 - inW * inH;
    return sum;
};
