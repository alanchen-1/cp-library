# Hashing - Polynomial Rolling

Hashes strings using the polynomial rolling hash function to enable constant time equality checking. Generates two hashes to reduce probability of undesired collisions (when two unequal strings hash to the same value). 

Not 100% deterministic, but the probability of a collision is negligible. 

Works under the namespace `Hashing` and provides the following structure.
## HashRange 
Instantiation example: 

	Hashing::HashRange hr;
or

	Hashing::HashRange hr("hello world");

### Functions
If instantiated without an initial string, call `add(string s)` first, then `hash(l, r)`.

| Function | Description | 
| ----------- | ----------- |
| `add(s)` | Adds string to prepare for hashing | 
| `hash(l, r)` | Hashes specified range, inclusive | 

## Misc Functions 
| Function | Description |
| ----------- | ----------- |
| `compute_hash(s)` | Computes hash of entire string, useful if you don't need the substring functionality |

## References
[12tqian](https://github.com/12tqian/cp-library/blob/main/library/string/hashing.hpp)