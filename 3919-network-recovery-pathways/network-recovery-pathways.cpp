class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> graph(n);
        vector<int> indegree(n,0);

        for(auto& e: edges){
            int u = e[0] , v=e[1], c=e[2];
            if(online[u] && online[v]){
                graph[u].emplace_back(v, c);
                indegree[v]++;
            }
        }

        int low = 0, high = 1e9, answer = -1;

        while(low <= high){
            int mid = low + (high - low )/2;
            if(isvalid(graph,indegree, n, k, mid)){
                answer = mid ;
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return answer;
    }

    private:
        bool isvalid(vector<vector<pair<int,int>>>& graph,vector<int> inorg, int n, long long k, int minedge){
            vector<long long> cost (n, LLONG_MAX);
            vector<int> indegree = inorg;
            queue<int> q;

            if(cost[0] == LLONG_MAX) cost[0] = 0;
            if(indegree[0] == 0) q.push(0);

            for(int i=0;i<n;++i){
                if(indegree[i]==0 && i!=0 ) q.push(i);
            }

            while(!q.empty()){
                int u=q.front();
                q.pop();

                for(auto& [v,c]: graph[u]){
                    indegree[v]--;

                    if(indegree[v]==0) q.push(v);

                    if(c>= minedge && cost[u] != LLONG_MAX && cost[u]+ c <cost[v]){
                        cost[v] = cost[u] + c;
                    }

                    
                }
            }

            return cost[n-1] <= k;
        }
};