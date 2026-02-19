class Solution {
public:
    typedef pair<int, int> P;
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>> adj; //adjacency list with u, v and weight. vector<P> kyun ki ek node ke multiple neighbours ho sakte hai
    
        for(auto &edge : edges){
            int u  = edge[0];
            int v  = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2*wt}); //reversed edge
        }

        priority_queue<P, vector<P>, greater<P>> pq; //min-heap
        vector<int> result(n, INT_MAX); //isme source ka baaki sare nodes se distance store karenge
        result[0] = 0; //0 ka 0 se distance 0 hi hoga
        pq.push({0, 0}); //{distance, node}

        while(!pq.empty()){
            int distance = pq.top().first;
            int node     = pq.top().second;
            pq.pop();

            if(node == n-1){
                return result[n-1]; //cost return kardo yaha tak ka
            }
            //node ka neighbours
            for(auto &p : adj[node]){ //is node ke neighbour ko dekhenge
                int adjnode = p.first;
                int adjdist = p.second;

                if(distance + adjdist < result[adjnode]){
                    result[adjnode] = distance + adjdist;
                    pq.push({distance + adjdist, adjnode});
                }
            }
        }
        return -1;
    }
};