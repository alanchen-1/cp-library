# Sparse Table

SparseTableIndex can be used with any operators that have an index associated with them. SparseTable is a general implementation that only supports querying the value, making it suitable for use with combination functions like gcd.

Does not support operations that are affected by overlap of ranges, like sums. Operations also need to be associative. 

To change the combination function, just change the code in `comb(a, b)`.

`l` and `r` are assumed to be 0-indexed. 

## SparseTable

### Functions
| Function | Description | Complexity |
| ----------- | ----------- | ----------- |
| `binlog(x)` | Gets the greatest power of 2 not greater than x. Assumes x is an `int`. | O(1) |
| `comb(a, b)`| Combination function. Currently set to combine using `min(a, b)`. | O(1) |
| `query(l, r)` | Gets the `min` element in the range `[l, r]` | O(1) |
| `init(_v)` | Initializes the sparse table for vector `v` | O(nlog(n)) |

## SparseTableIndex
Exactly the same as SparseTable, except with support for the additional function`index(l, r)`:
| Function | Description | Complexity |
| ----------- | ----------- | ----------- |
|`index(l, r)`| Gets the index of the `min` element in the range `[l, r]` | O(1) | 
