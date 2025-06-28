//DFS
class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>> &adj, vector<bool>& visited, long long &size){
        visited[u] = true; //jis node par aaye hai usko visited mark kar do
        size++;
        for(int &v : adj[u]){ //ab is u se mai kaha kaha ja sakti hu
        if(!visited[v]){
            dfs(v, adj, visited, size);
        }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
        
        adj[u].push_back(v);//this is an undirected graph
        adj[v].push_back(u);//so both are connected to each other
        }
        vector<bool> visited(n, false);
        long long remainingNodes = n;
        long long result = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){//if not visited then dfs maro
                long long size = 0;
                dfs(i, adj, visited, size);
                result += (size)*(remainingNodes-size);
                remainingNodes -= size;
            }
        }
        
        return result;
    }
};

//full dry run and explanation in my DSA copy