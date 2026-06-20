using int2=pair<int, int>;
const int N=1e5+2;
static int2 R[N];
static constexpr int M=1<<10, mask=M-1, bshift=10;
int freq[M];

void radix_sort(int2* nums, int n) {
    int2* buffer=(int2*)alloca(n*sizeof(int2));  // buffer
    int2* in=nums;
    int2* out=buffer;

    // 3 rounds covers 30 bits 
    for (int round=0; round < 3; round++) {
        const int shift=round * bshift;
        memset(freq, 0, sizeof(freq));

        for (int i=0; i<n; i++)
            freq[(in[i].first >> shift) & mask]++;

        partial_sum(freq, freq+M, freq);

        for (int i = n - 1; i >= 0; i--) {
            int x = (in[i].first >> shift) & mask;
            out[--freq[x]] = in[i];
        }

        // Swap pointers for the next round
        swap(in, out);
    }
    //data is currently in buffer. We must copy it back to nums.
    if (in != nums) {
        memcpy(nums, in, n * sizeof(int2));
    }
}
class Solution {
public:
    static int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int m=restrictions.size();
        for(int i=0; i<m; i++)
            R[i]={restrictions[i][0], restrictions[i][1]};
        R[m]={1, 0};
        R[m+1]={n, n-1};
        m+=2;
        radix_sort(R, m);
              
        for(int i=1; i<m; i++)
            R[i].second=min(R[i].second, R[i-1].second-R[i-1].first+R[i].first);
        
        for(int i=m-2; i>=1; i--)
            R[i].second=min(R[i].second, R[i+1].second+R[i+1].first-R[i].first); 

        int ans=0;
        for(int i=0; i<m-1; i++){ 
            int peak=(R[i].second+R[i+1].second+R[i+1].first-R[i].first)/2;
            ans=max(ans, peak);
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();