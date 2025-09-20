class Solution {
public:
    //Agar s1[i] aur s2[i] equivalent hai to unke beech ek edge ban gayi.
    char DFS(unordered_map<char, vector<char>>& adj, char current, vector<int>& visited){ //humne ek graph banaya jisme har ek character ek node hai
        visited[current - 'a'] = 1; //mark the visited
        char minChar = current; //matlab abhi tak smallest character wahi hai jo node hum visit kar rahe hain
        for(char &v : adj[current]){ //Ab hum current ke saare neighbors (adj[current]) traverse karenge
            if(visited[v - 'a'] == 0){ //iska matlab hai ye character abhi tak visit nahi hua Tabhi DFS us character pe aage jaata hai
                minChar  = min(minChar, DFS(adj, v, visited)); //poore group ka smallest character track hota rahe
            }
        }
        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> adj;
        int n = s1.length();
        for(int i = 0; i<n; i++){
            char a = s1[i]; //Dono ko ek undirected edge se connect kar dete hain, kyunki equivalence dono taraf se hota hai (agar a ~ b hai, to b ~ a bhi hai).
            char b = s2[i];

            adj[a].push_back(b); //adjacency list ka groups banane ke liye
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

/*
adjacency list : 
a: {b}
b: {a, c}
c: {b}
*/

//Now optimized one bcoz DFS gives TLE for longer string



class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find.parent[x];
        }
        return parent[x];
    }

    void unite(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px<py){
            parent[py] = px;
        }
        else {
            parent[px] = py;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
    }
};