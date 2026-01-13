//adjacency list banao or DFS chalake connected nodes ka track rakho

/*
DFS ka kaam hai:- Agar main abhi node par khada hoon,
kya main yahan se destination tak pahunch sakta hoon?
 */
class Solution {
public:
    bool dfs(int node, int dest, vector<vector<int>>& adj, vector<bool>& visited){
        if(node == dest) return true; //jis node pe khada hu wahi destination hai, matlb pahunch gaya
        visited[node] = true;

        for(int i : adj[node]){
            if(!visited[i]){
                if(dfs(i, dest, adj, visited))
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto & i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool>visited(n, false);
        return dfs(source, destination, adj, visited);
    }
};