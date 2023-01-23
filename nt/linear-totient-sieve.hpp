#pragma once

template <int N> struct LinearTotientSieve(){
	std::bitset<N> is_prime;
	std::vector<int> primes;
	vector<int> phi(N);

	LinearTotientSieve(){
		is_prime.set();
		is_prime[0] = is_prime[1] = 0;
		phi[1] = 1;

		for(int i = 2; i < N; i++){
			if(is_prime[i]){
				primes.push_back(i);
				phi[i] = i - 1;
			}

			for(int j = 0; j < (int) primes.size() && i * primes[j] < N; j++){
				is_prime[i * primes[j]] = 0;
				if(i % primes[j] == 0){
					// jth prime divides i
					phi[i * primes[j]] = phi[i] * primes[j];
					break;
				}else{
					// jth prime doesn't divide i
					phi[i * primes[j]] = phi[i] * phi[primes[j]];
				}
			}
		}
	}
}
