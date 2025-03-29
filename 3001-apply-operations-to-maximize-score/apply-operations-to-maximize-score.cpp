const int N = sqrt(100000);
vector<bool> isPrime(N + 1, true);
vector<int> prime;

class Solution {
public:
    const int mod = 1e9 + 7; 
    void Sieve() {
        if (!prime.empty()) return;
        isPrime[0] = isPrime[1] = false;
        const int n_sqrt = sqrt(N);
        for (int i = 2; i <= n_sqrt; i++) {
            if (isPrime[i]) {
                prime.push_back(i);
                for (int j = i * i; j <= N; j += i)
                    isPrime[j] = false;
            }
        }
        for (int i = n_sqrt + 1; i <= N; i++) {
            if (isPrime[i]) prime.push_back(i);
        }
    } 
    int prime_score(int x) {
        if (x <= N && isPrime[x]) return 1;
        int xsqrt = sqrt(x);
        int cnt = 0;
        for (int p : prime) {
            if (p > xsqrt) break;
            if (x % p != 0) continue;
            while (x % p == 0) x /= p;
            cnt++;
        }
        cnt += (x > 1);
        return cnt;
    } 
    long long modPow(long long x, int exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * x) % mod;
            x = (x * x) % mod;
            exp >>= 1;
        }
        return res;
    } 
    int maximumScore(vector<int>& nums, int k) {
        const int n = nums.size();
        Sieve(); 
        vector<int> score(n), left(n), right(n);
        for (int i = 0; i < n; i++) {
            score[i] = prime_score(nums[i]);
        } 
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && score[i] > score[st.top()]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        } 
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && score[i] >= score[st.top()]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        } 
        vector<pair<int, int>> num_idx(n);
        for (int i = 0; i < n; i++) {
            num_idx[i] = {nums[i], i};
        } 
        stable_sort(num_idx.rbegin(), num_idx.rend()); 
        long long ans = 1;
        for (int i = 0; i < n && k > 0; i++) {
            auto [x, idx] = num_idx[i];
            int exp = min((long long)(idx - left[idx]) * (right[idx] - idx), (long long)k);
            ans = (ans * modPow(x, exp) % mod);
            k -= exp;
        } 
        return ans;
    }
};