# Question
There are `n` cities numbered from `0` to `n - 1` and `n - 1` roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by `connections` where `connections[i] = [ai, bi]` represents a road from city `ai` to city `bi`.

This year, there will be a big event in the capital (city `0`), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city `0`. Return the **minimum** number of edges changed.

It's **guaranteed** that each city can reach city `0` after reorder.

**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2020/05/13/sample_1_1819.png)
```
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
```
**Example 2:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2020/05/13/sample_2_1819.png)
```
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
```
**Example 3:**<br/>
```
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
```

**Constraints:**

- `2 <= n <= 10^5`
- `connections.length == n - 1`
- `connections[i].length == 2`
- `0 <= ai, bi <= n - 1`
- `ai != bi`

<h1 align="center">Solution</h1>

# Breath First Search

## Intuition
This problem requires us to distinguish the arrows pointing towards city 0 from the other arrows that point in the opposite direction. To achieve this, we can use ticks (represented as pairs) and add them to the vector of vectors. Each vector in the vector of vectors corresponds to one node in the graph and contains a pair that specifies the node's child and the direction of the edge. If the direction is 1, it indicates that the edge is pointing away from city 0, while if it is 0, the edge is pointing towards city 0.



## Complexity
- Time complexity: O(V+E), where V is the number of vertices (cities) and E is the number of edges (roads) in the graph. It is because we visit each vertex once and explore all of its connected vertices.

- Space complexity: O(V+E), where V is the number of vertices (cities) and E is the number of edges (roads) in the graph. It is because we visit each vertex once and explore all of its connected vertices.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/solutions/3337041/solving-the-maze-a-breadth-first-search-approach-in-cpp/)


# Deapth First Search

## Intuition
This problem requires us to distinguish the arrows pointing towards city 0 from the other arrows that point in the opposite direction. To achieve this, we can use ticks (represented as pairs) and add them to the vector of vectors. Each vector in the vector of vectors corresponds to one node in the graph and contains a pair that specifies the node's child and the direction of the edge. If the direction is 1, it indicates that the edge is pointing away from city 0, while if it is 0, the edge is pointing towards city 0.

## Approach
This code is an implementation of a depth-first search algorithm that solves a problem related to graph theory.

The function takes in two arguments, an integer n representing the number of nodes in the graph, and a vector of vectors connections, where each inner vector contains two integers representing an edge in the graph.

The function first creates an adjacency list representation of the graph, where each node is a pair of integers. The first integer represents the neighbor node, and the second integer represents the direction of the edge. Specifically, a directed edge from node i to node j has a direction of 1, while an edge from j to i has a direction of 0.

Next, the function initializes a count variable to 0 and calls a recursive DFS function called "dsf" starting from the root node (node 0). During the DFS, the function traverses the graph and adds to the count variable the number of edges that need to be reversed to make the graph a rooted tree.

Finally, the function returns the count variable.

The DFS function takes in the adjacency list, the parent node of the current node, the current node, and the count variable. It then recursively visits all the children of the current node and updates the count variable accordingly. Specifically, if the direction of the edge between the current node and the child node is from the child to the current node (sign=0), the function increments the count variable, since this edge needs to be reversed to make the graph a rooted tree. The function continues the DFS from the child node until all nodes have been visited.

## Complexity
- Time complexity: O(V+E), where V is the number of vertices (cities) and E is the number of edges (roads) in the graph. It is because we visit each vertex once and explore all of its connected vertices.

- Space complexity: O(V+E), where V is the number of vertices (cities) and E is the number of edges (roads) in the graph. It is because we visit each vertex once and explore all of its connected vertices.

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/solutions/3337039/solving-the-maze-a-depth-first-search-approach-in-cpp/)