class Solution {
public:
    const int mod = 1'000'000'007;

    using Matrix = array<array<long long, 4>, 4>;

    Matrix mul(const Matrix& a, const Matrix& b) {
        Matrix x{};
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (a[i][j])
                    for (int k = 0; k < 4; ++k)
                        if (b[j][k])
                            x[i][k] = (x[i][k] + a[i][j] * b[j][k] % mod) % mod;
        return x;
    }

    int numTilings(int n) {
        Matrix mat = {{
            {0, 1, 0, 1},
            {1, 1, 0, 1},
            {0, 2, 0, 1},
            {0, 0, 1, 0}
        }};
        Matrix ans{};
        for (int i = 0; i < 4; ++i) ans[i][i] = 1;

        while (n > 0) {
            if (n & 1) ans = mul(ans, mat);
            mat = mul(mat, mat);
            n >>= 1;
        }

        return static_cast<int>(ans[1][1]);
    }
};