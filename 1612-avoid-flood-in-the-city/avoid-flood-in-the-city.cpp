class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int n=rains.size();
        vector<int> ans(n, 1); // dry lake 1 by default
        unordered_map<int,int> rainDay; // lake -> last rain day
        rainDay.reserve(n);
        set<int> dry; //dry days

        for (int i=0; i<n; i++) {
            if (rains[i]==0) 
                dry.insert(i); //dry day 
            else {
                const int lake=rains[i];
                const auto it0=rainDay.find(lake);
                if (it0!=rainDay.end()) {
                    int prev=it0->second;
                    // find dry day after prev
                    auto it=dry.lower_bound(prev);
                    if (it==dry.end()) return {}; // no dry day available
                    int d=*it;
                    ans[d]=lake; // dry this lake on day d
                    dry.erase(it); //  dry day used
                }
                rainDay[lake]=i;
                ans[i]=-1; // rainy day
            }
        }
        return ans;
    }
};