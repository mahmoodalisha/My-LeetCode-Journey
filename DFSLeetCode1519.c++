//cycle nahi hai
//and all the dry run in my DSA copy including global count 
class Solution {
public:

    void dfs(unordered_map<int, vector<int>> &adj, int curr, int parent, vector<int>& result, string &labels, vector<int> &count){
        char myLabel = labels[curr]; //jis node pe mai hu uska label kya hai nikaal lo
        int count_before_visiting_curr_children = count[myLabel - 'a'];//current node aur uske children ko explore karne se pehle ka count hai mere label ka

        //now explore
        count[myLabel-'a'] += 1; //jis node par mai hu uspe ek label to hai hi
        for(int &v : adj[curr]){
            if(v == parent) continue;
            dfs(adj, v, curr, result, labels, count);
        }
        //now its now time to write after variable
        int count_after_visiting_curr_children = count[myLabel - 'a'];
        result[curr] = count_after_visiting_curr_children-count_before_visiting_curr_children;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> adj;
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v); //becoz its undirected graph
            adj[v].push_back(u); //becoz its undirected graph

        }
        vector<int> result(n, 0);
        vector<int> count(26, 0);

        dfs(adj, 0, -1, result, labels, count); //dfs zero se start karre the, aur zero ka koi parent hi nahi hai toh -1 rakh liya baaki aage jaake parent update hota rahega
        return result;
    }
};