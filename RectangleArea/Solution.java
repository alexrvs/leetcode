public class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        int inL = A > E ? A : E;
        int inR = C < G ? C : G;
        int inB = B > F ? B : F;
        int inT = D < H ? D : H;
        int inW = inR > inL ? inR - inL : 0;
        int inH = inT > inB ? inT - inB : 0;
        return area1 + area2 - (inW * inH);
    }
}
