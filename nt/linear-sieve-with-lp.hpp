const int MAXN = 1e6; // CHANGE

struct LinearSieveLP {
    std::vector<int> lp;
    std::vector<int> primes;

    LinearSieveLP(int N){
        lp = std::vector<int>(N + 1);
        for (int i=2; i <= N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                primes.push_back(i);
            }
            for (int j = 0; i * primes[j] <= N; j++) {
                lp[i * primes[j]] = primes[j];
                if (primes[j] == lp[i]) {
                    break;
                }
            }
        }
    }
};

LinearSieveLP sv(MAXN);

std::vector<int> prime_factors(int x) {
    std::vector<int> ans;
    while (x > 1) {
        if (ans.empty() || ans.back() != sv.lp[x]) {
            ans.push_back(sv.lp[x]);
        }
        x /= sv.lp[x];
    }
    return ans;
}
