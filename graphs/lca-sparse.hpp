template <class T> struct SparseTableIndex {
	std::vector<T> v;
	std::vector<std::vector<int>> st; 
	
	SparseTableIndex(){}
	SparseTableIndex(const std::vector<T>& _v) {init(_v);}

	int binlog(int x){
		return 31 - __builtin_clz(x);
	}

	int comb(int a, int b){
        // use max for ties
		return v[a] == v[b] ? std::max(a, b) : (v[a] < v[b] ? a : b);
	}

	void init(const std::vector<T>& _v){
		v = _v;
		int n = v.size();
		st = {std::vector<int>(n)};

		for(int i = 0; i < n; i++){
			st[0][i] = i;
		}

		for(int j = 1; (1 << j) <= (int) n; j++){
			st.push_back(std::vector<int>((int) n - (1 << j) + 1));
			for(int i = 0; i + (1 << j) - 1 < n; i++){
				st[j][i] = comb(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	int index(int l, int r){
		assert(l <= r);
		int k = binlog(r - l + 1);
		return comb(st[k][l], st[k][r - (1 << k) + 1]);
	}

	T query(int l, int r){
        assert(l >= 0); assert(r < (int) v.size());
		return v[index(l, r)];
	}
};

struct LCA {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> depth, first;
    std::vector<std::pair<int, int>> euler;
    SparseTableIndex<std::pair<int ,int>> sparse_table;
    std::vector<bool> visited;

    void init(int _n) {
        n = _n;
        adj.resize(n);
        euler.reserve(2 * n);
        depth = first = std::vector<int>(n);
        visited = std::vector<bool>(n, false);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int cur) {
        visited[cur] = true;
        first[cur] = (int) euler.size();
        euler.emplace_back(depth[cur], cur);

        for (auto &next : adj[cur]) {
            if (visited[next]) continue;
            depth[next] = depth[cur] + 1;
            dfs(next);
            euler.emplace_back(depth[cur], cur);
        }
    }

    void gen(int root = 0) {
        dfs(root);
        sparse_table.init(euler);
    }

    int lca(int u, int v) {
        u = first[u];
        v = first[v];
        if (u > v) std::swap(u, v);
        return sparse_table.query(u, v).second;
    }

    int dist(int u, int v) {
        // inclusion exclusion
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};
