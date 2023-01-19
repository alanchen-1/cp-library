std::vector<int> phi(int n) {
    std::vector<int> p(n + 1);
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (p[i] == i) {
            // hasn't been touched yet, nec a prime
            for (int j = i; j <= n; j += i) {
                // divided by a prime
                p[j] -= p[j] / i;
            }
        }
    }
    return p;
}
