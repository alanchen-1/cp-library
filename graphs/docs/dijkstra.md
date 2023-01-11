# Dijkstra's 
Solves single source shortest path using Dijkstra's algorithm in O(nlog(n)) (priority queue/min heap optimization). Can be used on weighted and unweighted (set all weights equal to 0 or something), and directed and undirected graphs. 

Assumes 0-indexed. 

Provides the following structure and functions:
## Dijkstra
Create structure using `Dijkstra<W, directed>` where:
`W` = type of weight (usually numerical, like `int` or `long long`)
`directed` - boolean describing if graph is directed or not 

### Attributes
| Name | Description|
|------| -----------|
| `N` | Size of graph | 
| `dist` | Vector of shortest distances to each node. Need to call `run` before this variable contains meaningful data.|
| `adj` | Adjacency list representation of graph |

### Functions
| Name | Description | Complexity |
| `init(N)` | Initializes structure to fit size `N` graph | O(N) | 
| `add_edge(u, v, w)` | Adds an edge from `u` to `v` with weight `w`. Adds the edge going from `v` to `u` only if `directed = true`. | O(1) | 
| `run(start)` | Runs Dijkstra's algorithm starting from `start`. | O(Nlog(N)) |

A general progression of function/attribute calls would be `init` --> `E` * `add_edge` --> `run` --> `.dist`.
