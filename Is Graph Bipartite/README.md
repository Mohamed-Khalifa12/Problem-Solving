# Question
## 785. Is Graph Bipartite?
There is an **undirected** graph with `n` nodes, where each node is numbered between `0` and `n - 1`. You are given a 2D array `graph`, where `graph[u]` is an array of nodes that node `u` is adjacent to. More formally, for each `v` in `graph[u]`, there is an undirected edge between node `u` and node `v`. The graph has the following properties:

- There are no self-edges (`graph[u]` does not contain `u`).
- There are no parallel edges (`graph[u]` does not contain duplicate values).
- If `v` is in `graph[u]`, then `u` is in `graph[v]` (the graph is undirected).
- The graph may not be connected, meaning there may be two nodes `u` and `v` such that there is no path between them.

A graph is **bipartite** if the nodes can be partitioned into two independent sets `A` and `B` such that **every** edge in the graph connects a node in set `A` and a node in set `B`.

Return `true` *if and only if it is **bipartite.***<br/>

**Example 1:**<br/>
![image](https://assets.leetcode.com/uploads/2020/10/21/bi2.jpg)
```
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
```
**Example 2:**<br/>
![image](https://assets.leetcode.com/uploads/2020/10/21/bi1.jpg)
```
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
```

**Constraints:**

- `graph.length == n`
- `1 <= n <= 100`
- `0 <= graph[u].length < n`
- `0 <= graph[u][i] <= n - 1`
- `graph[u]` does not contain `u`.
- All the values of `graph[u]` are **unique**.
- If `graph[u]` contains `v`, then `graph[v]` contains u.

*You can try to solve this problem from [here](https://leetcode.com/problems/is-graph-bipartite/description/)*

<h1 align="center">Solution</h1>

## Intuition
In this problem, we have two options: either we use the BFS (Breadth-First Search) algorithm or the DFS (Depth-First Search) algorithm to solve the 'Is Graph Bipartite?' problem. The main idea behind solving this problem is to assign a color to each node and ensure that all connected nodes have the opposite color of the initial node. We proceed by moving to the next level and verifying that all connected nodes have the opposite color of the current node (the initial one). We repeat this process until we reach the end of the graph. If this condition holds true until the end, the graph is bipartite. However, if the condition fails at any point, we return false.

## BFS Approach

1. Initialize the number of nodes, `n`, based on the size of the input graph.
2. Create a `colour` array of size `n` and initialize all elements to 0. This array will be used to assign colors to nodes.
3. Iterate over each node in the graph.
4. If the current node already has a color assigned (i.e., `colour[node] != 0`), skip to the next node.
5. Assign the color 1 to the current node (`colour[node] = 1`).
6. Create an empty queue, `q`, and enqueue the current node.
7. Start a loop that continues until the queue `q` becomes empty.
8. Dequeue the front element from the queue and assign it to `current`.
9. Iterate over each neighbor of the `current` node.
10. If the neighbor has not been assigned a color yet (i.e., `colour[neighbour] == 0`), assign the opposite color of the `current` node to the neighbor (`colour[neighbour] = -colour[current]`) and enqueue the neighbor.
11. If the neighbor has the same color as the `current` node (i.e., `colour[neighbour] == colour[current]`), return `false` since the graph is not bipartite.
12. Repeat steps 7 to 11 until all nodes and their neighbors are processed.
13. If the loop completes without finding any conflicts, return `true` since the graph is bipartite.

```
function isBipartite(graph):
    n = graph.size()
    colour = new array of size n, initialized with 0

    for node = 0 to n-1:
        if colour[node] != 0:
            continue
        
        colour[node] = 1
        q = new queue
        q.push(node)

        while q is not empty:
            current = q.front()
            q.pop()

            for neighbour in graph[current]:
                if colour[neighbour] == 0:
                    colour[neighbour] = -colour[current]
                    q.push(neighbour)
                else if colour[neighbour] == colour[current]:
                    return false

    return true
```

## DFS Approach

1. Initialize the number of nodes, `n`, based on the size of the input graph.
2. Create a `color` array of size `n` and initialize all elements to 0. This array will be used to assign colors to nodes.
3. Iterate over each node in the graph.
4. If the current node does not have a color assigned yet (i.e., `color[node] == 0`), call the `validColouring` function to check if the coloring of the node and its neighbors is valid.
5. If the `validColouring` function returns `false`, it means the graph is not bipartite, so return `false`.
6. If the loop completes without finding any conflicts, return `true`, indicating that the graph is bipartite.

The `validColouring` function performs a depth-first search (DFS) traversal on the graph, assigning colors to nodes and ensuring that adjacent nodes have different colors. It follows the following steps:

1. If the current node already has a color assigned (i.e., `color[node] != 0`), check if the current color (`col`) matches the assigned color (`color[node]`). If they are different, return `false` since the graph is not bipartite.
2. If the current node does not have a color assigned yet, assign the current color (`col`) to the node (`color[node] = col`).
3. Iterate over each neighbor of the current node.
4. Recursively call the `validColouring` function for each neighbor, passing the opposite color (`-col`).
5. If any recursive call returns `false`, it means the coloring is invalid, so return `false`.
6. If all recursive calls complete without finding any conflicts, return `true`, indicating a valid coloring.

```
function isBipartite(graph):
    n = graph.size()
    color = new array of size n, initialized with 0

    for node = 0 to n-1:
        if color[node] == 0 and not validColouring(graph, color, node, 1):
            return false

    return true

function validColouring(graph, color, node, col):
    if color[node] != 0:
        return col == color[node]

    color[node] = col

    for neighbour in graph[node]:
        if not validColouring(graph, color, neighbour, -col):
            return false

    return true
```

## Complexity
- Time complexity: O(V + E),  where V is the number of vertices (nodes) and E is the number of edges in the graph.

- Space complexity: O(V), where V is the number of vertices (nodes).

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/is-graph-bipartite/solutions/3541240/easy-cpp-solution-with-pseudocode/)