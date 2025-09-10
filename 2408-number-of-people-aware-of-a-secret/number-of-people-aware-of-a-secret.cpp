class Solution {
public:
    int M = 1e9+7;
    vector<int> t;

    int solve(int day, int delay, int forget){
        if(day == 1) return 1;

        if(t[day] != -1) return t[day];

        long long result = 0;
        for(int prev = day - forget + 1; prev <= day - delay; prev++){
            if(prev > 0){
                result = (result + solve(prev, delay, forget)) % M;
            }
        }
        return t[day] = result;  // stores in dp
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        t.assign(n+1, -1);

        long long total = 0;
        for(int day = n - forget + 1; day <= n; day++){
            if(day > 0){
                total = (total + solve(day, delay, forget)) % M;
            }
        }
        return total;
    }
};