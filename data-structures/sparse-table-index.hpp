template <class T> struct SparseTableIndex {
	std::vector<T> v;
	std::vector<std::vector<int>> st; 
	
	SparseTableIndex(){}
	SparseTableIndex(const std::vector<T>& _v) {init(_v);}

	int binlog(int x){
		return 31 - __builtin_clz(x);
	}

	int comb(int a, int b){
		return v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);
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

	int query(int l, int r){
        assert(l >= 0); assert(r < (int) v.size());
		return v[index(l, r)];
	}
};
