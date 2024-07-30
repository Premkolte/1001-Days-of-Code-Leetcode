class Solution {
public:
    int minimumDeletions(string& s) {
        const int n=s.size();
        vector<int> B_pre(n), A_suf(n);//0-based prefix sums & suffix sums
        B_pre[0]=s[0]=='b';
        A_suf[0]=count(s.begin(), s.end(), 'a');// Count 'a' in s
        for(int i=1; i<n; i++){
            B_pre[i]=B_pre[i-1]+(s[i]=='b');
            A_suf[i]=A_suf[i-1]-(s[i-1]=='a');
        }
        int cnt=n;
        for(int i=0; i<n; i++){
            cnt=min(cnt, B_pre[i]+A_suf[i]-1);
        }
        return cnt;
    }
};




auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();