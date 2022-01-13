# Disjoint Set Union/Union Find

Provides functions to unionize sets/check if two elements are in the same set in amortized O($\alpha$(x)), where $\alpha(x)$ is the inverse Ackermann function (nearly constant). Does so through path compression and union by size (small to large) optimizations. 

## DSU

### Attributes

| Name | Description |
| ------ | -------|
| `parent` | Vector storing reference to parent. Negative value means it is the representative element, and the absolute value is the size of the set. |

### Functions

| Function | Description | Complexity |
| --------- | --------- | ------------|
| `init(n)` | Initializes DSU structure with size `n` | O(n) |
| `find(x)` | Finds the representative element of `x`'s set | O(alpha(n)) |
| `same_set(a, b)` | Checks if two elements are in the same set | O(alpha(n)) |
| `size(x)` | Returns size of `x`'s set | O(alpha(n)) |
| `unite(x, y)` | Unites `x`'s set and `y`'s set. Returns `false` if `x` and `y` are in the same set. | O(alpha(n)) |


