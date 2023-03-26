# Question
You are given a **directed** graph of `n` nodes numbered from `0` to `n - 1`, where each node has **at most one** outgoing edge.

The graph is represented with a given 0-indexed array `edges` of size `n`, indicating that there is a directed edge from node `i` to node `edges[i]`. If there is no outgoing edge from node `i`, then `edges[i] == -1`.

Return the length of the longest cycle in the graph. If no cycle exists, return `-1`.

A cycle is a path that starts and ends at the same node.

**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2022/06/08/graph4drawio-5.png)
```
Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.
```
**Example 2:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-1.png)
```
Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.
```

**Constraints:**

- `n == edges.length`
- `2 <= n <= 10^5`
- `-1 <= edges[i] < n`
- `edges[i] != i`

<h1 align="center">Solution</h1>

## Intuition
we can depend on a depth-first search (DFS) algorithm to explore all possible cycles in the graph. For each vertex v in the graph, we start a DFS traversal from v and keep track of the visited vertices and the path we have taken so far. If we encounter a vertex that has already been visited, we have found a cycle, and we can compare its length with the length of the longest cycle found so far.

To avoid exploring the same cycle multiple times, we can use a boolean array to mark the visited vertices and only explore vertices that have not been visited yet. However, it is possible to visit a node in a different cycle than the current one. To prevent this, we can use an unordered map to store each edge and a counter for the number of times it has been visited. When we encounter a node that already exists in the loop, we know that we have found a cycle. To confirm this, we check if the node has been visited before and exists in the map. If it satisfies both conditions, we compare it to the other cycles found so far

## Approach
During the DFS traversal, the code marks the current node as visited and checks if its neighbor has not been visited yet. If the neighbor has not been visited, the code recursively calls the DFS function with the neighbor as the new node, updates the distance of the neighbor from the current node in the unordered map, and continues the traversal.

If the neighbor has been visited before, the code checks if the distance of the neighbor from the current node is already stored in the unordered map. If it is, then the code has found a cycle, and it calculates the length of the cycle using the stored distance values. If the length of the cycle is greater than the current result, the result is updated with the length of the cycle.


## Complexity
- Time complexity: O(V*(V+E)), where V is the number of vertices and E is the number of edges in the graph.

- Space complexity: O(V*(V+E)), where V is the number of vertices and E is the number of edges in the graph.


## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/longest-cycle-in-a-graph/solutions/3345205/easy-solution-with-explanation-a-depth-first-search-based-algorithm/)
