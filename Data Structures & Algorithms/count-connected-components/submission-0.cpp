class Solution {
public:

    void dfs(int i, int n, vector<vector<int>>& adj, vector<int>& vis)
    {
        if(i>=n || vis[i]==1) return;

        vis[i] = 1;

        for(int j{0}; j<adj[i].size(); j++)
        {
            int neigh = adj[i][j];
            if(vis[neigh]==0)
            {
                dfs(neigh,n,adj,vis);
            }
        }
        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        vector<int> vis(n,0);

        for(int i{0};i<n; i++)
        {
            if(vis[i]==0)
            {
                dfs(i,n,adj,vis);
                ans++;
            }
        }

        return ans;
    }
};
