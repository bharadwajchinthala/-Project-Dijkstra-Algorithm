## Input and Output

## Input

Enter number of vertices: 5

Enter number of edges: 6

Enter edges in format: u v w (0-indexed nodes)

0 1 2

0 2 4

1 2 1

1 3 7

2 4 3

3 4 2

Enter start node (0-4): 0

Enter end node (0-4): 4

## Output

Shortest cost from 0 to 4 is: 6

Path: 0 -> 1 -> 2 -> 4

## Explanation of Example


The graph has 5 vertices (0–4) and 6 edges.


We want the shortest path from node 0 to node 4.


Dijkstra’s algorithm calculates that the best path is:


0 → 1 → 2 → 4


The total cost is 6.

## Example (No Path Case)

Input

Enter number of vertices: 3

Enter number of edges: 1

Enter edges in format: u v w (0-indexed nodes)

0 1 5

Enter start node (0-2): 0

Enter end node (0-2): 2

Output

No path exists from 0 to 2

## Notes

Vertices are 0-indexed (first node is 0).


The graph is treated as undirected (edges are stored both ways).


If there is no path, the program prints a clear message.
