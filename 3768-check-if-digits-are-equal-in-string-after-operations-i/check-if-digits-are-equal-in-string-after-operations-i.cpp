class Solution {
public:
    bool hasSameDigits(string s) {
        int i = 0;
        string res = "";
        while (s.size() > 2 && i < s.size() - 1) {
            res += (s[i] + s[i + 1]) % 10;
            i++;
            if (i == s.size() - 1) {
                s = res;
                i = 0;
                res = "";
            }
        }
        return s.size() == 2 and s[0] == s[1];
    }
};