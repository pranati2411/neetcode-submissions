class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
        vis[0] =1;
        queue<pair<int,int>> q;
        q.push({-1,0});

        while(!q.empty())
        {
            int p = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i{0}; i<adj[x].size(); i++)
            {
                int neigh = adj[x][i];
                if(vis[neigh]==0)
                {
                    vis[neigh]=1;
                    q.push({x,neigh});
                }
                else if(neigh!=p)
                {
                    return false;
                }
            }
        }

        for(int i{0}; i<n; i++)
        {
            if(vis[i]==0) return false;
        }

        return true;
    }
};
