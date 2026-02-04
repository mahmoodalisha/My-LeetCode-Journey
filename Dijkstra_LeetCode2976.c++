class Solution {
public:
    const long long INF = 1e18;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> adj(26); // adjacency list: adj[u] = {v, cost}

        for(int i = 0; i<original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i]  - 'a';
            adj[u].push_back({v, cost[i]});
        }

        // dist[i][j] = minimum cost i -> j
        vector<vector<long long>> dist(26, vector<long long>(26, INF)); //matrix that's keeping the track of the minimum cost
        //now applying Dijkstra
        for(int src = 0; src<26; src++){
            priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
            > pq;

            dist[src][src] = 0; //a -> b -> c -> d tak jaane ka kitna total cost hua
            pq.push({0, src}); //source se source jaane ka cost 0 hota hai

            while(!pq.empty()){
                auto [currentCost, u] = pq.top();
                pq.pop();

                if(currentCost > dist[src][u]) continue;

                for(auto [v, w] : adj[u]){
                    if(dist[src][v] > currentCost + w){
                        dist[src][v] = currentCost + w;
                        pq.push({dist[src][v], v});
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i<source.size(); i++){
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if(dist[s][t] == INF) return -1; //cheapest cost return karte hai
            ans += dist[s][t];
        }
        return ans;
    }
};

/*
adj[0] = { {1,2} };         a → b (cost 2)                  adj[0].push_back({1, 2});
adj[1] = { {2,5} };         b → c (cost 5)                  adj[1].push_back({2, 5});
adj[2] = { {1,5}, {4,1} };  c → b (cost 5) c → e (cost 1)   adj[2] = { (1,5), (4,1) }
adj[3] = { {4,20} };        d → e (cost 20)                 adj[3].push_back({4, 20});
adj[4] = { {1,2} };         e → b (cost 2)                  adj[4].push_back({1, 2});

So Dijkstra can discover paths like
a → b → c
a → b → c → e
c → e → b

 */