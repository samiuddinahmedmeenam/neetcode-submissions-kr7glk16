class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
      

        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int out = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(adj, visited, i);
                out++;
            }
        }

        return out;
    }

    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int i){
        visited[i] = true;

        for(auto x: adj[i]){
            if(!visited[x]){
                dfs(adj, visited, x);
            }
        }
    }
};
