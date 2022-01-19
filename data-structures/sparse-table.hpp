#pragma once

template <class T> struct SparseTable{
	std::vector<T> v;
	std::vector<std::vector<T>> st; 
	
	SparseTable(){}
	SparseTable(const std::vector<T>& _v) {init(_v);}

	int binlog(int x){
		return 31 - __builtin_clz(x);
	}

	T comb(T a, T b){
		return std::min(a, b); // change operation
	}

	void init(const std::vector<T>& _v){
		v = _v;
		int n = v.size();
		st = {v};

		for(int j = 1; (1 << j) <= n; j++){
			st.push_back(std::vector<T>(n - (1 << j) + 1));
			for(int i = 0; i + (1 << j) - 1 < n; i++){
				st[j][i] = comb(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	T query(int l, int r){
		assert(l <= r); assert(l >= 0); assert(r < (int) v.size());
		int k = binlog(r - l + 1);
		return comb(st[k][l], st[k][r - (1 << k) + 1]);
	}
};
