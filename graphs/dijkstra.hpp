template<class W, bool directed> struct Dijkstra{
    int N; 
    std::vector<W> dist;
    std::vector<std::vector<std::pair<int, C>>> adj;

    void init(int _N){
        N = _N;
        adj.clear(); adj.resize(N);
    }

    void add_edge(int u, int v, W weight){
        adj[u].emplace_back(v, weight);
        if(!directed){
            adj[v].emplace_back(u, weight);
        }
    }

    void run(int start){
        dist = std::vector<W>(N, std::numeric_limits<W>::max());
        std::priority_queue<pair<W, int>, std::vector<pair<W, int>>, std::greater<pair<W, int>>> pq;

        auto add = [&](int a, W b){
            if(dist[a] > b){
                dist[a] = b;
                pq.push({b, a});
            }
        };

        dist[start] = 0;
        pq.push({0, start});

        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            if(dist[cur.second] < cur.first) continue;
            for(pair<int, C>& next : adj[cur.second]){
                int a = next.first;
                W b = cur.first + next.second;
                if(dist[a] > b){
                    dist[a] = b; 
                    pq.push({b, a});
                }
            }
        }
    }
};
