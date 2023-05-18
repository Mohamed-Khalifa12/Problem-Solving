# Question

## 1557. Minimum Number of Vertices to Reach All Nodes

Given a **directed acyclic graph**, with `n` vertices numbered from `0` to `n-1`, and an array `edges` where `edges[i] = [fromi, toi]` represents a directed edge from node `fromi` to node `toi`.

Find *the smallest set of vertices from which all nodes in the graph are reachable*. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.<br/>

**Example 1:**<br/>
![image](https://assets.leetcode.com/uploads/2020/07/07/untitled22.png)
```
Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]
Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].
```
**Example 2:**<br/>
![image](https://assets.leetcode.com/uploads/2020/07/07/untitled.png)
```
Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
Output: [0,2,3]
Explanation: Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. Also any of these vertices can reach nodes 1 and 4.
```

**Constraints:**
- `2 <= n <= 10^5`
- `1 <= edges.length <= min(10^5, n * (n - 1) / 2)`
- `edges[i].length == 2`
- `0 <= fromi, toi < n`
- All pairs `(fromi, toi)` are distinct.

*you can try to solve the problem from [here](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/)*

<h1 align="center">Solution</h1>

## Intuition
In this problem, we just identify the nodes where incoming edges are directed and exclude them from the list of the minimum number of vertices required to reach all nodes.

## Approach

1. Initialize an empty result vector to store the vertices that do not have any incoming edges.
2. Create a boolean vector, `isComingEdgeExists`, of size `n` (number of nodes) and initialize all values to `false`. This vector will be used to mark nodes where incoming edges exist.
3. Iterate over each edge in the `edges` vector.
4. For each edge, mark the node at index `edge[1]` as having an incoming edge by setting `isComingEdgeExists[edge[1]]` to `true`.
5. Iterate from 0 to `n-1`.
6. For each node index `i`, check if `isComingEdgeExists[i]` is `false`.
7. If `isComingEdgeExists[i]` is false, it means the node `i` does not have any incoming edges. Add `i` to the result vector.
8. Return the result vector containing the vertices that do not have any incoming edges.

```
function findSmallestSetOfVertices(n, edges):
    result = empty vector of integers
    isComingEdgeExists = empty vector of booleans of size n, initialized to false

    for each edge in edges:
        isComingEdgeExists[edge[1]] = true

    for i from 0 to n-1:
        if isComingEdgeExists[i] is false:
            result.push_back(i)

    return result
```

## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/solutions/3537842/easy-cpp-solution-with-explanation-and-pseudocode/)