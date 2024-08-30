class Solution {
public:
    using int2=pair<int, int>;// (weight, vertex)
    int n, m;
    vector<vector<int2>> adj;
    vector<int> wild_edges;
    inline void build_graph(vector<vector<int>>& edges){
        for(int i=0; i<m; i++){
            auto& e=edges[i];
            int u=e[0], v=e[1], w=e[2];
            if (w>0){
            //    cout<<w<<",";
                adj[u].emplace_back(w, v);
                adj[v].emplace_back(w, u);
            }
            else {
            //    cout<<"mut:"<<i<<",";
                wild_edges.push_back(i);
            }
        }
    }
    
    int dijkstra(int src, int des, vector<vector<int2>>& adj){
        int dist[100];
        fill(dist, dist+n, INT_MAX);
        priority_queue<int2, vector<int2>, greater<int2>> pq;
        pq.emplace(0, src);
        dist[src]=0;

        while (!pq.empty()) {
            auto [d0, i] = pq.top();
            pq.pop();
            if (i == des) return d0;
            for (auto& [d_next, j] : adj[i]) {
                int new_d = d0 + d_next;
                if (new_d < dist[j]) {
                    dist[j] = new_d;
                    pq.emplace(new_d, j);
                }
            }
        }
        return INT_MAX;
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        this->n=n;
    //    cout<<n<<endl;
        adj.resize(n);
        m=edges.size();
    //    cout<<"m="<<m<<endl;
        build_graph(edges);

        int dist=dijkstra(source, destination, adj);
   //     cout<<"dist="<<dist<<endl;
        if (dist< target) return {};
        
        for (auto i: wild_edges)
            edges[i][2]=target+1;// weight= target+1
        if (dist==target) return edges;
        
        for (auto i: wild_edges){
            auto& new_edge=edges[i];
            int u=new_edge[0], v=new_edge[1];
            new_edge[2]=1;
            adj[u].emplace_back(1, v);
            adj[v].emplace_back(1, u);
            dist=dijkstra(source, destination, adj);
        //    cout<<"add edges["<<i<<"] dist="<<dist<<endl;
            if (dist<=target) {
                new_edge[2]+=target-dist;
        //        cout<<"last i="<<i<<", w="<<edges[i][2]<<endl;
                return edges; 
            }
        }
        return {};
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();