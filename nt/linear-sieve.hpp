#pragma once

template <int N> struct LinearSieve{
	std::bitset<N> is_prime;
	std::vector<int> primes;

	LinearSieve(){
		is_prime.set();
		is_prime[0] = 0;
		is_prime[1] = 0;

		for(int i = 2; i < N; i++){
			if(is_prime[i]){
				primes.push_back(i);
			}
			for(int j = 0; j < (int)primes.size() && i * primes[j] < N; j++){
				is_prime[i * primes[j]] = 0;
				if(i % primes[j] == 0){
					break;
				}
			}
		}
	}
};

