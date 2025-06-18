class Solution {
public:

    char DFS(unordered_map<char, vector<char>>& adj, char current, vector<int>& visited){
        visited[current - 'a'] = 1; //mark the visited
        char minChar = current; //initialize a minimum character
        for(char &v : adj[current]){
            if(visited[v - 'a'] == 0){
                minChar  = min(minChar, DFS(adj, v, visited));
            }
        }
        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> adj;
        int n = s1.length();
        for(int i = 0; i<n; i++){
            char a = s1[i];
            char b = s2[i];

            adj[a].push_back(b); 
            adj[b].push_back(a);
        }
        int m = baseStr.length();
        string result;
        for(int i = 0; i<m; i++){
            char ch = baseStr[i];
            vector<int>visited(26,0);
            result.push_back(DFS(adj, ch, visited));
        }
        return result;
    }
};