# Linear Sieve

Finds all primes between 1 and n in O(n) time. Can be used for any multiplicative function `f` by determining the behavior under the following conditions:

1. `x` is prime --> directly compute `f(x)`
2. `x = ip` and `i (mod p) != 0` --> since `f` is multiplicative, `f(x) = f(i)f(p)`
3. `x = ip` and `i (mod p) == 0` --> need relationship between `f(i)` and `f(ip)`
 
Euler's totient function (how many numbers less than n are relatively prime to n) is a simple example, where the behavior in case 3 is just f(ip) = pf(i).

The code is included as an example in linear-totient-sieve.hpp. 
