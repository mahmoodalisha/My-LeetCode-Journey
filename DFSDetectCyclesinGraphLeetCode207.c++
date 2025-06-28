//cycle Detection sum only
class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;

        for(int neighbor : adj[node]){
            if(visited[neighbor] == 0){
                if(!dfs(neighbor, adj, visited)) return false;//Agar neighbor course me cycle milti hai, toh abhi ke course ke liye bhi false return kar do.
            }
            else if (visited[neighbor] == 1){
                // back edge → cycle
                return false;
            }
        }
        visited[node] = 2; // done visiting
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //make a graph
        unordered_map<int, vector<int>> adj;
        for(vector<int> &vec : prerequisites){
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u); // To take course u, you must first take course v
        }

        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited)) return false;
            }
        }

        return true;
    }
};
/*
We use a vector<int> visited where:
0 = unvisited
1 = visiting (currently in call stack)
2 = visited
If during DFS we revisit a visiting (1) node → cycle detected
 */

 /* 
 neighbor ek aisa course hai jise current course ke baad lena hai.

Agar neighbor already visiting ho (visited == 1) → matlab ek cycle ban rahi hai.

Agar cycle milti hai toh turant false return karte hain.
 */