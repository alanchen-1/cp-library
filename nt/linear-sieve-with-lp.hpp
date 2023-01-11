template <int N> struct LinearSieveLP(){
    vector<int> lp(N+1);
    vector<int> primes;

    LinearSieveLP(){
        for (int i=2; i <= N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                primes.push_back(i);
            }
            for (int j=0; j < (int) primes.size() && primes[j] <= lp[i] && i*primes[j] <= N; ++j) {
                lp[i * primes[j]] = primes[j];
            }
        }
    }
}
