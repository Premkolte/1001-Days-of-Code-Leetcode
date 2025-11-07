#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, long long k) {
        int n = stations.size();
        vector<long long> diff(n + 5, 0);

        // Build initial power difference array
        for (int i = 0; i < n; ++i) {
            diff[max(0, i - r)] += stations[i];
            diff[min(n - 1, i + r) + 1] -= stations[i];
        }

        // Compute minimum current power (lo) and set a large upper bound (hi)
        vector<long long> prefix(n, 0);
        prefix[0] = diff[0];
        long long lo = prefix[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + diff[i];
            lo = min(lo, prefix[i]);
        }
        long long hi = 2e10;  // safe upper bound

        auto check = [&](long long mid) -> bool {
            vector<long long> temp = diff;
            long long cur = 0, cnt = 0;
            for (int i = 0; i < n; ++i) {
                cur += temp[i];
                if (cur < mid) {
                    long long need = mid - cur;
                    cnt += need;
                    if (cnt > k) return false;
                    cur = mid;
                    if (i + 2 * r + 1 < n)
                        temp[i + 2 * r + 1] -= need;
                }
            }
            return true;
        };

        // Binary search for the maximum possible minimum power
        while (lo < hi) {
            long long mid = (lo + hi + 1) >> 1;
            if (check(mid))
                lo = mid;
            else
                hi = mid - 1;
        }

        return lo;
    }
};