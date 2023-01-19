template <class T> struct FenwickTree {
    std::vector<T> tree;
    int n;

    FenwickTree(int n) {
        this->n = n;
        tree.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (int i = 0; i < (int) a.size(); i++) {
            add(i, a[i]);
        }
    }

    T sum(int r) {
        T ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ans += tree[r];
        return ans;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add (int idx, T delta) {
        for (; idx < n; idx = idx | (idx + 1))
            tree[idx] += delta;
    }
};
