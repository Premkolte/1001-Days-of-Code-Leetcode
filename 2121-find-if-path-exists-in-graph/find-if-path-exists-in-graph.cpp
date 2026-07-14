class Solution {
public:
    void dfs(int node, vector<int> adjls[], vector<int> &vis){
        vis[node] = 1;
        for(auto it:adjls[node]){
            if(!vis[it]){
                dfs(it, adjls, vis);
            }
            
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {


        vector<int> adjls[n];
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjls[u].push_back(v);
            adjls[v].push_back(u); // Assuming the graph is undirected
        }
        vector<int> vis(n,0);
        dfs(source, adjls, vis);

        return vis[destination] == 1;
    }
};