# Question
You are given an integer `n`. There is an undirected graph with `n` nodes, numbered from `0` to `n - 1`. You are given a 2D integer array `edges` where `edges[i] = [ai, bi]` denotes that there exists an undirected edge connecting nodes `ai` and `bi`.

Return *the **number of pairs** of different nodes that are **unreachable** from each other.*
**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2022/05/05/tc-3.png)
```
Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
```
**Example 2:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2022/05/05/tc-2.png)
```
Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.
```

**Constraints:**

- `2 <= n <= 10^5`
- `0 <= edges.length <= 2 * 105`
- `edges[i].length == 2`
- `1 <= ai, bi <= n`
- `ai != bi`
- There are no repeated edges.

<h1 align="center">Solution</h1>

# Breath First Search

## Intuition
To solve this problem is to count the number of pairs of nodes that are connected by a path and then subtract it from the total number of pairs of nodes in the graph.

To find the number of pairs of nodes that are connected by a path, we can use Breadth First Search (BFS). This involves creating a queue and adding the starting node and all its connected nodes to it. We then count the number of nodes in the connected subgraph, and remove them from the queue until all nodes have been visited. This gives us the total number of nodes in the connected subgraph.

Once we have counted the number of pairs of nodes that are connected by a path for each connected component, we can subtract it from the total number of pairs of nodes in the graph to obtain the number of pairs of nodes that are not connected by any path.

## Approach
1. Build an adjacency list for the graph using the given edges.
2. Initialize a variable countPairsValue to zero.
3. Create a boolean array isVisited of size n to keep track of the nodes that have been visited during the BFS.
4. For each unvisited node i in the graph:
a. Create a queue and add the current node i to it.
b. Initialize a variable sizeOfComponent to 0.
c. While the queue is not empty:
i. Remove the first node from the queue.
ii. Increment sizeOfComponent by 1.
iii. Mark the current node as visited in the isVisited array.
iv. Add all unvisited neighbors of the current node to the queue.
d. Increment countPairsValue by the product of the size of the current component and the number of unvisited nodes in the graph (i.e., n - size of the current component).
e. Update the count of unvisited nodes in the graph by subtracting the size of the current component from n.
5. Return countPairsValue.

## Complexity
- Time complexity: O(V+E), where V is the number of vertices and E is the number of edges in the graph.

- Space complexity: O(V+E), where V is the number of vertices and E is the number of edges in the graph.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/solutions/3341322/easy-solution-breadth-first-search-based/)



# Deapth First Search

## Intuition
To solve this problem is to count the number of pairs of nodes that are connected by a path and then subtract it from the total number of pairs of nodes in the graph.

To count the number of pairs of nodes that are connected by a path, we can use Depth First Search (DFS) to traverse the graph and count the number of nodes in each connected component.

Once we have counted the number of pairs of nodes that are connected by a path for each connected component, we can subtract it from the total number of pairs of nodes in the graph to obtain the number of pairs of nodes that are not connected by any path.
 

## Approach
The algorithm to solve this problem can be implemented as follows:

1. Create an adjacency list to represent the graph.

2. Initialize a vector of bools to keep track of which nodes have been visited during the DFS.

3. Initialize a variable countPairs to 0 to keep track of the number of pairs of nodes that are connected by a path.

4. For each unvisited node in the graph, perform a DFS starting from that node to count the number of nodes in the connected component.

5. For each connected component, calculate the number of pairs of nodes that are connected by a path.

6. Subtract countPairs from the total number of pairs of nodes in the graph. This gives the number of pairs of nodes that are not connected by any path.

7. Return the result.

## Complexity
- Time complexity: O(V+E), where V is the number of vertices and E is the number of edges in the graph.

- Space complexity: O(V+E), where V is the number of vertices and E is the number of edges in the graph.


## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/solutions/3341319/easy-solution-depth-first-search-based/)