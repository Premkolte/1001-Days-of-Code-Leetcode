class Solution {
public:
    long long reverse(int x) {
        long long rev = 0;
    while(x)
        {
            int p = x%10;
            rev= rev *10 + p;
            x = x/10;
        }
        if(rev > INT_MAX || rev < INT_MIN){return 0;}
        return rev;
    }
};