constexpr int Mx=5e4+1;
int8_t mu[Mx];
vector<int> prime, sq_free;
bitset<Mx> isPrime;
using ll=long long;
void Sieve_mu(){
    if (mu[1]==1) return; // compute exactly once
    memset(mu, 1, sizeof(mu));
    isPrime.set();
    isPrime[0]=isPrime[1]=0;
    prime.reserve((int)(Mx/log(Mx)));
    sq_free.reserve((int)(0.6*Mx));
    mu[1]=1;
    for(int i=2; i<Mx; i++){
        if(isPrime[i]){
            prime.push_back(i);
            mu[i]=-1;
            for(int j=i*2; j<Mx; j+=i){
                isPrime[j]=0;
                mu[j]=-mu[j];
            }
            ll i2=(ll)i*i;
            // not square-free
            for(ll j=i2; j<Mx; j+=i2) 
                mu[j]=0;
        }
    }
    for(int i=1; i<Mx; i++) 
        if (mu[i]!=0) sq_free.push_back(i);
}

// Div[i]= number of x's in nums divisible by i
ll Div[Mx];
ll freq[Mx];
class Solution {
public:
    static vector<int> gcdValues(vector<int>& nums, vector<long long>& q) {
        Sieve_mu();
        const int n=nums.size();
        int M=0;
        for (int x : nums){
            M=max(M, x);
            Div[x]++;// count x
        } 
        for(int x=1; x<=M; x++){
            for(int y=2*x; y<=M; y+=x)
                Div[x]+=Div[y];// add Div[y] to Div[x]
        }

        // compute GCD pair counts for each divisor
        for (int x=1; x<=M; x++) {
            long long cnt=Div[x];
            Div[x]=cnt*(cnt-1LL)/2; // Number of pairs with GCD = x
        }
        // Moebius inversion
        for (int x=1; x<=M; x++) {
            freq[x]=0;
            for (int k : sq_free) {// consider only square-free
                if (x*k>M) break; 
                freq[x]+=mu[k]*Div[x*k];
            }     
        }

        // Reuse freq for Prefix sum of GCD pair 
        partial_sum(freq, freq+(M+1), freq);
        
        //using upper_bound
        int qz=q.size();
        vector<int> ans(qz);
        for (int i=0; i<qz; i++) {
            ans[i]=upper_bound(freq, freq+M+1, q[i])-freq; 
        }
        // reset for the next testcase
        memset(Div, 0, (M+1)*sizeof(ll));
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();