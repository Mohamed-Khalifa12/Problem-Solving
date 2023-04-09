# Question
## 133. Clone Graph
Given a reference of a node in a [connected](https://en.wikipedia.org/wiki/Connectivity_(graph_theory)#Connected_graph) undirected graph.

Return a [deep copy](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) (clone) of the graph.

Each node in the graph contains a value (`int`) and a list (`List[Node]`) of its neighbors.

```
class Node {
    public int val;
    public List<Node> neighbors;
}
```

**Test case format:**
For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with `val == 1`, the second node with `val == 2`, and so on. The graph is represented in the test case using an adjacency list.

**An adjacency list** is a collection of unordered **lists** used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with `val = 1`. You must return the **copy of the given node** as a reference to the cloned graph.<br/>

**Example 1:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2019/11/04/133_clone_graph_question.png)
```
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
```
**Example 2:**<br/>
![Screenshot](https://assets.leetcode.com/uploads/2020/01/07/graph.png)
```
Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
```

**Example 3:**<br/>
```
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
```

**Constraints:**

* The number of nodes in the graph is in the range `[0, 100]`.
* `1 <= Node.val <= 100`
* `Node.val` is unique for each node.
* There are no repeated edges and no self-loops in the graph.
* The Graph is connected and all nodes can be visited starting from the given node.

*You can try to solve this problem from [here](https://leetcode.com/problems/clone-graph/description/)*

<h1 align="center">Solution</h1>

# Intuition
<h6>The algorithm maintains an unordered map that maps each original node to its corresponding clone node. It then performs a DFS traversal on the graph, starting from the given node, and creates a clone of each node it visits. For each node visited, it also adds its corresponding clone node to the unordered map.

While performing the DFS traversal, when the algorithm encounters a neighbor of the current node, it checks if the neighbor node has already been cloned and added to the unordered map. If it has, it simply retrieves the cloned node from the map and adds it to the list of neighbors of the current node's clone. Otherwise, it recursively calls the DFS function on the neighbor node to create its clone and add it to the list of neighbors of the current node's clone.

Once the DFS traversal is complete, the algorithm returns the clone node of the given node, which will have all of the same connections as the original graph, but with each node and edge represented by a unique object in memory.</h6>

# Approach
1. Initialize an empty unordered map to store the clones of the original nodes.
2. Check if the given node is NULL or has no neighbors. If it doesn't have any neighbors, create a new clone node with the same value as the original node and return it.
3. If the given node has neighbors, perform a DFS traversal starting from the given node.
4. For each node visited during the DFS traversal, create a clone of that node and add it to the unordered map.
5. For each neighbor of the current node, check if it has already been cloned and stored in the unordered map. If it has, retrieve its clone node from the map. Otherwise, recursively call the DFS function on the neighbor node to create its clone and add it to the current node's list of neighbors.
6. Once the DFS traversal is complete, return the clone node of the original node.

# Complexity
- Time & Space complexity: O(N), where N is the number of nodes in the graph.


## LeetCode
You can examine the problem and solution more closely from [LeetCode](https://leetcode.com/problems/clone-graph/solutions/3396685/easy-dfs-solution-with-explanation/)