struct DSU{
	std::vector<int> parent;	
	
	void init(int N){
		parent = std::vector<int>(N, -1);
	}

	int find(int x){
		if(parent[x] < 0){
			return x;
		}
		return parent[x] = find(parent[x]);
	}
	
	bool same_set(int a, int b){
		return find(a) == find(b);
	}

	int size(int x){
		return -parent[find(x)];
	}

	bool unite(int x, int y){
		x = find(x); y = find(y);
		if(x == y){
			return false;
		}
		if(parent[x] > parent[y]){
			std::swap(x, y);
		}
		parent[x] += parent[y]; 
		parent[y] = x;
		return true;
	}

};
