class Solution {
public:
    string getHint(string secret, string guess) {
        int size = secret.size();
        vector<int> s(10, 0);
        vector<int> g(10, 0);
        int b = 0;
        int c = 0;
        for (int i = 0; i < size; i++) {
            if (secret[i] == guess[i]) b++;
            s[secret[i] - '0']++;
            g[guess[i] - '0']++;
        }
        for (int i = 0; i < 10; i++) {
            //c += s[i] < g[i] ? s[i] : g[i];
            if (s[i] < g[i]) {
                c += s[i];
            } else {
                c += g[i];
            }
        }
        c -= b;
        stringstream stream;
        stream << b << "A" << c << "B";
        string res = stream.str();
        return res;
    }
};
