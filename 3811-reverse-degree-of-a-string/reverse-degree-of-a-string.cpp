class Solution {
public:
    int reverseDegree(string s) {
        int nn = s.length();
        int summ = 0;

    for (int i = 0; i < nn; i++) {
        int rev = 26 - (s[i] - 'a'); 
        summ += rev * (i + 1);
    }

    return summ;
    }
};