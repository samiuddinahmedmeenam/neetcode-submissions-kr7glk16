class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n){
            return false;
        }

        vector<vector<int>> adj(n);
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        unordered_set<int> visited;
        if(!dfs(0, -1, visited, adj)){
            return false;
        }

        return visited.size() == n;
    }


    bool dfs(int node, int prev, unordered_set<int>& visited, vector<vector<int>>& adj){
        if(visited.count(node)){
            return false;
        }

        visited.insert(node);
        for(auto x: adj[node]){
            if(x == prev){
                continue;
            }

            if(!dfs(x, node, visited, adj)){
                return false;
            }
        }

        return true;
    }
};
