template <int N> struct Sieve {
	bitset<N> isprime; // up to N
	vector<int> primes; // primes up to sqrt(N)

	Sieve() {
		isprime.set();
		isprime[0] = 0; isprime[1] = 0;
		// mark all mults of 2 as composite
		for(int i = 4; i < N; i+=2){
			isprime[i] = 0;
		}
        primes.push_back(2);
		// begin iterating until sqrt(N)
		for(int i = 3; i * i < N; i++){
			if(isprime[i]){
				primes.push_back(i);
				for(int j = i * i; j <= N; j += i){
					isprime[j] = 0;
				}
			}	
		}
	}
}
