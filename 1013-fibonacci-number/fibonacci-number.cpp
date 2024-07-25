class Solution {
public:
//0 1 1 2 3 5 8 11
    int fibbo(int n)
{
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

    int fib(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;
        else return fibbo(n-1) + fibbo(n-2);
    }
};