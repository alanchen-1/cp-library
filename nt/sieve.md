# Sieve

Finds all prime numbers between `[1, n]` in O(nlog(log(n))).

Reminder to self: `primes` only stores the primes up to `sqrt(n)`. Use `is_prime` if you need access to bigger primes. 

I used this like once, until finding out that there exists a linear complexity version that accomplishes the same thing plus more; check [`./nt/linear-sieve.hpp`](https://github.com/alanchen-1/cp-library/blob/main/nt/linear-sieve.hpp). 
