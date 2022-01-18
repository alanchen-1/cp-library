# modint
Provides operations to work modulo `MOD`, where the only assumption is that `MOD` is prime to allow for fast (O(log(n)) modular inverse computation w/ Fermat's Little Thm and binary exponentiation. 

If looking for fast mod inverse (still O(log(n))) for any `MOD` (not necessarily prime), look at `../nt/number-theory.hpp`.


